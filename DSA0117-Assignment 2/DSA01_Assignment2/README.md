# DSA01 – Assignment 2 (CO2)
## Properly formatted C++ source code and sample outputs

### Folder structure
Each task has the same clear structure:

- `Source_Code/` – readable, properly indented C++ program.
- `Output/Sample_Output.txt` – output produced by compiling and running that program.
- `Output/Execution_Details.txt` – compile command and run instructions.

### Tasks included
1. Q1 – Call by Value, Reference and Pointer
2. Q2 – Return by Reference and Its Dangers
3. Q3 – Default Arguments and Function Overloading
4. Q4 – Specifying a Class with an Array Inside It
5. Q5 – Static Members and Arrays of Objects
6. Q6 – Friend Functions and Inline Functions
7. Q7 – Diagnose, Redesign and Validate (circular-buffer redesign example)

### Compile and run
Example:
```bash
g++ -std=c++17 -Wall -Wextra Source_Code/Q1_Call_By_Value_Reference_Pointer.cpp -o program
./program
```
On Windows, run `program.exe`.

### Before submitting
- Add your name, register number, and actual compiler/version.
- Run each program on your own computer and capture terminal screenshots.
- Prepare the written report required by the assignment: predictions made before execution, explanations, alternative designs, complexity analyses, tests, and actual measurements.
- Q6 requires your own timing experiment at `-O0` and `-O2`.
- Q7 requires comparison of the original and redesigned versions using the same tests.
- Create the repository `DSA01-<RegisterNumber>-Assignment2` and commit each task progressively.

**Note:** The `.txt` outputs are sample execution transcripts, not screenshots. Q7 is a sample redesign implementation; the assignment's diagnosis, objective, prediction, comparison measurements, and defence still need to be written using your own evidence.
