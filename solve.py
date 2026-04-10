#!/usr/bin/env python3
"""
Logic Gates I - CTF Solver
Hardware Hacking, 100 pts

The circuit in the image is an RTL (Resistor-Transistor Logic) circuit
with 4 inputs (A, B, C, D) and a single output bit.

The input file contains 512 4-bit nibbles (space-separated binary strings).
Each nibble is fed directly as: A=bit0, B=bit1, C=bit2, D=bit3 (MSB-first).

The circuit implements a boolean function of A, B, C, D.
We enumerate all 2^16 possible 4-input boolean functions and keep the one
whose output (512 bits → 64 bytes) decodes to readable ASCII.

The output turns out to be a Base64-encoded string containing the flag.
"""

import base64

def solve(input_path: str) -> str:
    with open(input_path) as f:
        nibbles = f.read().split()

    assert len(nibbles) == 512, f"Expected 512 nibbles, got {len(nibbles)}"

    # Pre-compute the index for each nibble: index = (A<<3)|(B<<2)|(C<<1)|D
    indices = []
    for nib in nibbles:
        a, b, c, d = int(nib[0]), int(nib[1]), int(nib[2]), int(nib[3])
        indices.append((a << 3) | (b << 2) | (c << 1) | d)

    # Try all 65536 boolean functions (each is a 16-bit truth table)
    for func_int in range(65536):
        func_table = [(func_int >> i) & 1 for i in range(16)]

        output_bits = [func_table[idx] for idx in indices]

        # Pack 512 bits into 64 bytes
        result_bytes = []
        for i in range(0, 512, 8):
            byte_val = 0
            for bit in output_bits[i:i+8]:
                byte_val = (byte_val << 1) | bit
            result_bytes.append(byte_val)

        decoded = bytes(result_bytes)

        # Check if fully printable ASCII
        if all(32 <= b <= 126 for b in decoded):
            text = decoded.decode("ascii")
            # Try to Base64-decode if it looks like Base64
            if text.endswith("==") or text.endswith("="):
                try:
                    inner = base64.b64decode(text).decode("ascii")
                    if inner.startswith("SoterCTF{"):
                        return inner
                except Exception:
                    pass
            if text.startswith("SoterCTF{"):
                return text

    return "Flag not found"


if __name__ == "__main__":
    import sys
    path = sys.argv[1] if len(sys.argv) > 1 else "uploads/input.txt"
    flag = solve(path)
    print(f"Flag: {flag}")
