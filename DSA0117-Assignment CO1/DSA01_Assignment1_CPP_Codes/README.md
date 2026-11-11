# DSA01 Assignment 1 – C++17 Programs

Each task has a separate `.cpp` file. Compile from this folder using:

```bash
g++ -std=c++17 -Wall -Wextra Task01_Objects.cpp -o task01
```

Run on Windows:
```bash
task01.exe
```

Run on Linux/macOS:
```bash
./task01
```

Repeat with the required filename for each task.

## Files
- Task01_Objects.cpp – objects, classes, and basic fare calculation
- Task02_Tokens_Constants.cpp – constexpr constants and enum class
- Task03_Data_Types.cpp – data types, sizeof, ranges, and collection
- Task04_Conversions.cpp – implicit and explicit conversions
- Task05_Operators.cpp – precedence, increment, conditional, division and modulus
- Task06_Control_Structures.cpp – completed switch-based fare() and canTravel()
- Task07_Procedural_vs_OOP.cpp – procedural and class-based SmartCard
- Task08_Safe_Input_Output.cpp – validated input and formatted output
- Task09_Implement_Test_Fare.cpp – table-driven fare tests
- Task10_Collection_Comparison.cpp – integer paise and double totals
- Task11_Final_Design.cpp – recommended design for the original requirements
- Task12_Design_Challenge.cpp – Airport zone, weekend discount, and monthly pass

## Important assignment assumptions
1. Money is stored as integer paise to avoid floating-point rounding.
2. Peak hours are 08:00–09:59 and 17:00–19:59. Therefore exactly 10:00 and 20:00 are off-peak.
3. The assignment does not specify the student/senior concession percentage or eligibility rules, so no concession percentage is invented in these programs.
4. In Task 12, a monthly pass covers the two selected zones and makes journeys in those zones free. Weekend discount is applied instead of peak surcharge, never together.
5. Task 10 uses Rs 10 per journey as a consistent example to compare totals. Replace this with measured journey fares if your experiment uses another fare mix.

Run every program yourself, save screenshots of input/output, and add your own name/register number and evidence to the report. These programs are starter implementations; verify them with your compiler before submission.
