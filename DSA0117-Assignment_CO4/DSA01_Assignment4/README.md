# DSA01 – Assignment 4 (CO4)
## C++ class hierarchies, inheritance and polymorphism

Each task is organized in the same format as Assignment 3:
- `Source_Code/` contains readable C++17 source files.
- `Output/` contains a separate sample output transcript for each source file and execution details.

## Tasks
1. Staff payroll hierarchy and switch-based alternative.
2. University people hierarchy, virtual diamond and predicted-output variants.
3. Constructor/destructor order and completed initializer-list program.
4. Virtual account repair using smart pointers and static/virtual dispatch prediction.
5. Cart methods using `this`, chaining, object access and pointer-array traversal.
6. Vehicle rental abstract hierarchy, polymorphic fleet, late return charge and ElectricBus extension; plus switch alternative.

## Build
Use:
`g++ -std=c++17 -Wall -Wextra <source-file.cpp> -o program`
Run `program.exe` on Windows or `./program` on Linux/macOS.

## Before submission
- Fill in your name, register number, compiler/version and GitHub repository link.
- Run each source file locally and save terminal screenshots in the matching `Output/` folder.
- The assignment report also requires written diagnoses, UML diagrams, access tables, predictions made before execution, construction/destruction traces, complexity comparisons and design defence.
- Run Task 4 with AddressSanitizer and include your actual sanitizer report. The supplied repaired version demonstrates safe polymorphic ownership; it does not fabricate sanitizer evidence for the defective starter code.
- For Task 3, swap initializer-list order in a separate experiment and record your compiler warning. For Task 2, compare `sizeof` and name access in virtual and non-virtual/composition designs.
- Create GitHub repository `DSA01-<RegisterNumber>-Assignment4` and commit each task progressively.

**Output note:** `.txt` files are sample execution transcripts produced by compiling the included programs. They are not screenshots from your computer. Predictions, sanitizer logs, measurements and report explanations must be completed and verified by you.
