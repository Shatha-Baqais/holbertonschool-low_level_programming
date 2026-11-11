# Simple Calculator

A terminal-based interactive calculator written in C.

## Compile

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run

./calculator

## Supported operations

- 1) Add
- 2) Subtract
- 3) Multiply
- 4) Divide
- 0) Quit

## Numeric behavior

Operands are integers (int). Division truncates the result toward zero.

## Known limitations

- Only numeric input is supported. Entering non-numeric input (for example `x` or `hello`) may cause unexpected behavior.
