#!/usr/bin/env python3
"""
Solver for the "Logic Gates II" CTF challenge (SoterCTF).

Circuit analysis (falsad.txt - Falstad/CircuitJS1 format):
- 4 inputs: A (y=240), B (y=272), C (y=304), D (y=336)
- I (InverterElm, code='I'): NOT gate applied to A before Gate1
- 154 (XorGateElm, code=154): XOR gate
- Circuit:
    Gate1 (XOR, 2 inputs): XOR(NOT(A), B) = XNOR(A, B)
    Gate2 (XOR, 2 inputs): XOR(C, D)
    NOT(Gate2): XNOR(C, D)
    Gate3 (XOR, 2 inputs): XOR(XNOR(A,B), XNOR(C,D))
    Final NOT: Output = XNOR(XNOR(A,B), XNOR(C,D))
              = 1 iff (A==B) == (C==D)

Processing:
- input.txt: space-separated 4-bit binary tokens (ABCD)
- Each token → 1 output bit via the circuit
- 212504 tokens → 212504 bits → 26563 bytes → JPEG image
- JPEG image contains the flag text

Flag: SoterCTF{Peresoso_a1_poder}
"""

import sys
import os


def compute_output(token: str) -> int:
    """Apply the circuit function to a 4-bit binary token string."""
    A = int(token[0])
    B = int(token[1])
    C = int(token[2])
    D = int(token[3])
    xnor_ab = 1 - (A ^ B)   # Gate1: XOR(NOT(A), B) = XNOR(A,B)
    xnor_cd = 1 - (C ^ D)   # NOT(Gate2): NOT(XOR(C,D)) = XNOR(C,D)
    xor_both = xnor_ab ^ xnor_cd  # Gate3: XOR(xnor_ab, xnor_cd)
    return 1 - xor_both      # Final NOT


def solve(input_file: str, output_file: str) -> None:
    """Process input tokens through the circuit and save resulting JPEG."""
    print(f"Reading input from: {input_file}")
    with open(input_file, 'r') as f:
        tokens = f.read().split()

    print(f"Processing {len(tokens)} tokens...")
    bits = ''.join(str(compute_output(t)) for t in tokens)

    print(f"Converting {len(bits)} bits to {len(bits)//8} bytes...")
    output_bytes = bytes([int(bits[i:i+8], 2) for i in range(0, len(bits) - 7, 8)])

    # Verify JPEG magic bytes
    if output_bytes[:4] == b'\xff\xd8\xff\xe0':
        print("Output is a valid JPEG image!")
    else:
        print(f"Warning: unexpected magic bytes: {output_bytes[:4].hex()}")

    with open(output_file, 'wb') as f:
        f.write(output_bytes)
    print(f"JPEG saved to: {output_file}")
    print("\nTo read the flag, open the JPEG image.")
    print("Flag is visible as text in the image: SoterCTF{Peresoso_a1_poder}")


def extract_flag(jpeg_file: str) -> str:
    """Use OCR to extract the flag text from the JPEG image."""
    try:
        import easyocr
        reader = easyocr.Reader(['en'], gpu=False, verbose=False)
        result = reader.readtext(jpeg_file, detail=1)
        for bbox, text, conf in result:
            if 'SoterCTF' in text or '{' in text:
                return text
        return "Flag not found via OCR. Open the image manually."
    except ImportError:
        return "easyocr not installed. Open the image manually to read the flag."


if __name__ == '__main__':
    input_path = 'input.txt'
    output_path = 'output_flag.jpg'

    if len(sys.argv) >= 2:
        input_path = sys.argv[1]
    if len(sys.argv) >= 3:
        output_path = sys.argv[2]

    if not os.path.exists(input_path):
        print(f"Error: input file '{input_path}' not found.")
        sys.exit(1)

    solve(input_path, output_path)

    print("\nAttempting OCR to extract flag text...")
    flag = extract_flag(output_path)
    print(f"Extracted text: {flag}")
