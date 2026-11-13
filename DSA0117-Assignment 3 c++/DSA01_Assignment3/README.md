# DSA01 – Assignment 3 (CO3)

Properly formatted C++ source files and sample execution outputs for Q1–Q7.

## Folder layout
Each Task folder contains:
- `Source_Code/` – readable C++ source.
- `Output/Sample_Output.txt` – sample output from the included program.
- `Output/Execution_Details.txt` – compile/run commands.

## Tasks
Q1 Constructors and constructor overloading
Q2 Deep copy, copy assignment and destructor
Q3 Dynamic constructors and destructors
Q4 Arithmetic and stream operator overloading
Q5 Increment, comparison and subscript operators
Q6 Text class and Rule of Three
Q7 Complex-number impedance class

## Compile
`g++ -std=c++17 -Wall -Wextra Source_Code/<filename>.cpp -o program`

On Windows run `program.exe`; on Linux/macOS run `./program`.

## Before submission
Add your name, register number, compiler/version and GitHub link. Execute programs yourself and take console screenshots. The report must include predictions made before running, explanations, memory diagrams, sanitizer evidence, tests, timing measurements, complexity analysis and design decisions. Run Q2/Q3 with AddressSanitizer or Valgrind; perform Q5 timing at -O0/-O2; measure Q6 copies and compare with std::string; hand-check Q7 and compare with std::complex<double>. Create `DSA01-<RegisterNumber>-Assignment3` and commit each task progressively.

Note: text output files are sample transcripts, not screenshots from your own execution. Required experimental measurements and sanitizer reports are not fabricated or included.
