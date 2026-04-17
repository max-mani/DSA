#!/usr/bin/env python3
"""
Romeo and Juliet - CTF Solver
Easy, 100 pts

The challenge file is a program written in the Shakespeare Programming Language
(SPL). Each character in the play (here Romeo and Juliet) is a signed-integer
variable. The current speaker addresses the other character ("thou"/"thee")
with assignment statements that reduce to ordinary arithmetic:

  * "Thou art <noun phrase>."                       -> assign constant
  * "Thou art the sum of X and Y."                  -> X + Y
  * "Thou art the difference between X and Y."      -> X - Y
  * "Thou art the product of X and Y."              -> X * Y

Values of noun phrases are:
  * +1 for any "positive" noun (king, lord, rose, ...),
    -1 for any "negative" noun (pig, devil, wolf, ...).
  * Each adjective doubles the absolute value, regardless of polarity.
  * Pronouns "thyself" / "myself" refer to the listener / speaker.

"Speak your mind!" prints the listener's current value as an ASCII character.

Decoding Juliet's monologue in Act I, Scene II reveals the flag.
"""

import re
import sys

POSITIVE_NOUNS = {
    "angel", "cat", "chihuahua", "daughter", "door", "flower", "happiness",
    "heaven", "horse", "king", "lantern", "lord", "love", "plum", "purpose",
    "queen", "rose", "squirrel", "sun", "tree", "wind",
}
NEGATIVE_NOUNS = {
    "bastard", "beggar", "blister", "codpiece", "coward", "curse", "death",
    "devil", "draught", "flirt-gill", "goat", "hell", "hog", "hound", "leech",
    "lie", "pig", "plague", "starvation", "toad", "war", "wolf",
}

PRONOUNS_SELF = {"myself", "me", "i"}
PRONOUNS_OTHER = {"thyself", "thee", "thou", "you", "yourself"}


def phrase_value(text: str) -> int:
    """Evaluate a Shakespearean noun phrase like 'a fair noble king'."""
    words = re.findall(r"[a-z\-]+", text.lower())
    while words and words[0] in {"a", "an", "the"}:
        words.pop(0)
    if not words:
        return 0
    noun, adjectives = words[-1], words[:-1]
    if noun in NEGATIVE_NOUNS:
        sign = -1
    elif noun in POSITIVE_NOUNS:
        sign = 1
    else:
        sign = 1
    return sign * (2 ** len(adjectives))


def eval_expr(text: str, me: int, you: int) -> int:
    text = text.strip()
    low = text.lower().strip()
    if low in PRONOUNS_SELF:
        return me
    if low in PRONOUNS_OTHER:
        return you
    return phrase_value(text)


def evaluate_assignment(sentence: str, me: int, you: int) -> int:
    """Compute the RHS of 'Thou art ...' and return new value for the listener."""
    body = re.sub(r"^thou\s+art\s+", "", sentence.strip().rstrip(".!?"),
                  flags=re.IGNORECASE).strip()

    for op, fn in (
        ("the sum of",                 lambda a, b: a + b),
        ("the difference between",     lambda a, b: a - b),
        ("the product of",             lambda a, b: a * b),
    ):
        m = re.match(rf"{op}\s+(.+?)\s+and\s+(.+)$", body, flags=re.IGNORECASE)
        if m:
            return fn(eval_expr(m.group(1), me, you),
                      eval_expr(m.group(2), me, you))

    return eval_expr(body, me, you)


def run(script: str) -> str:
    values = {"romeo": 0, "juliet": 0}
    speaker = listener = None
    output = []

    for raw in script.splitlines():
        line = raw.strip()
        if not line:
            continue
        low = line.lower().rstrip(".!?:")

        if low in ("romeo", "juliet"):
            speaker = low
            listener = "juliet" if speaker == "romeo" else "romeo"
            continue
        if speaker is None:
            continue
        if low.startswith("thou art"):
            values[listener] = evaluate_assignment(
                line, values[speaker], values[listener])
            continue
        if low.startswith("speak your mind"):
            v = values[listener]
            output.append(chr(v % 0x110000) if 0 <= v < 0x110000 else f"[{v}]")
            continue
        if low.startswith("open your heart"):
            output.append(str(values[listener]))
            continue

    return "".join(output)


def solve(path: str) -> str:
    with open(path, encoding="utf-8") as f:
        return run(f.read())


if __name__ == "__main__":
    target = sys.argv[1] if len(sys.argv) > 1 else "RomeoAndJuliet.txt"
    print(f"Flag: {solve(target)}")
