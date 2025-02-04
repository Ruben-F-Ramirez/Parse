# Quadratic Equation Parser and Solver

## Overview
This project reads a file containing coefficients of quadratic equations, parses the input, and calculates the real roots using the quadratic formula. It demonstrates file handling, string parsing with `strtok`, and mathematical computations in C.

## Features
- Reads coefficients from a file provided via the command line.
- Parses input using `strtok` and converts values with `atoi`.
- Computes the discriminant of a quadratic equation.
- Solves for real roots using the quadratic formula.
- Outputs the roots if they are real; otherwise, indicates complex roots.

## File Structure
- `54_parse_Ruben_Ramirez.c`: Contains the main implementation.
- `README.md`: Documentation for the project.

## Compilation and Execution
### Prerequisites
- A C compiler such as `gcc`.

### Steps to Compile and Run
1. Open a terminal and navigate to the project directory.
2. Compile the program using:
   ```bash
   gcc 54_parse_Ruben_Ramirez.c -o quadratic_solver -lm
   ```
3. Run the executable with an input file:
   ```bash
   ./quadratic_solver input.txt
   ```

## Functions
### Core Functions
- `int polysolver(double aa, double bb, double cc, double discriminant, double *root1, double *root2)`: 
  - Computes the roots of the quadratic equation.
  - Returns `1` for real roots and `0` for complex roots.
- `double discriminant(double AA, double BB, double CC)`: 
  - Calculates the discriminant (`BB^2 - 4*AA*CC`).

## Example Input (input.txt)
```
1,-3,2
2,5,3
```

## Example Output
```
The quadratic equation is 1.00 X^2 + (-3.00) X + (2.00) = 0
The real roots of the quadratic equation are 2.000 and 1.000

The quadratic equation is 2.00 X^2 + (5.00) X + (3.00) = 0
The roots are complex
```

## Author
Programmed by Ruben Ramirez for CSCI 1320.

## License
This project is open-source and available for use under the MIT License.