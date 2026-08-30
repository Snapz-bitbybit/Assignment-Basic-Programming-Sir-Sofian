# Personality Test System (C++)

A console-based C++ application that manages users and determines their
personality type (Introvert / Ambivert / Extrovert) based on a 5-question
test. Built as a group assignment for **KMK1093 Basic Programming**, Faculty
of Cognitive Sciences and Human Development, Universiti Malaysia Sarawak
(UNIMAS).

**Title:** *The Analysis and Development of Application "Personality Test"
Using C++ Programming Language* — Group G1

## Overview

The system lets a user:
1. **Add a user** — enter an ID and name, answer 5 personality questions
   (rated 1–5 on a Rarely → Always scale), and the program calculates a
   total score and assigns a personality type:
   - Score ≤ 10 → **Introvert**
   - Score 11–20 → **Ambivert**
   - Score > 20 → **Extrovert**
2. **Delete a user** by ID
3. **Display all users** in a formatted table, sorted by ID (bubble sort)
4. **Exit** — collects a short 5-question feedback survey before closing

All user data persists to `users.txt` between runs; feedback responses are
appended to `feedback.txt`.

## Tech Stack

- **C++** (no external libraries — `<iostream>`, `<fstream>`, `<string>`, `<iomanip>` only)
- File-based storage (`users.txt`, `feedback.txt`)
- Console UI with input validation (cancel with `-1`, out-of-range re-prompt)

## How to Compile & Run

```bash
g++ -o personality_test personality_test_system.cpp
./personality_test        # on Linux/macOS
```

On Windows:
```bat
g++ -o personality_test.exe personality_test_system.cpp
personality_test.exe
```

> Note: the program calls `system("color 3")` to set the console text
> color — this is a Windows-only command (via `cmd.exe`) and will print a
> harmless "command not found" on Linux/macOS but does not affect the
> program's logic.

## Example

```
1. Add User
2. Delete User
3. Display Users
4. Exit
Enter your choice: 1
Enter User ID (or type -1 to cancel): 1
Enter User Name (or type 'exit' to cancel): kadro
1. Do you enjoy socializing?
 1: Rarely  2: Occasionally  3: Sometimes  4: Often  5: Always
Response (or type -1 to cancel): 2
...
User added successfully!
```

## Project Team (Group G1)

Roles per the project report: Introduction & task distribution, Need
Analysis, Design (Flowchart & Pseudocode), Development, Evaluation, and
Conclusion were divided among 5 group members. See the full report for
individual contributions.

**Lecturer:** Ts. Ahmad Sofian bin Shminan — KMK1093, Semester 1 2024/2025

## A Note on Versions in This Repo

This repository's source file (`personality_test_system.cpp`) was
transcribed and verified (compiled + tested against the report's own
sample data) from the **code screenshots in the submitted project report**
— that version has **4 menu options** (Add / Delete / Display / Exit).

Separately, the compiled `assignment_9_0.exe` that was actually submitted
for grading contains a **5th option ("Update User")** that does not appear
in the report's code screenshots or pseudocode — it was evidently added
after the report was written. The source for that newer version wasn't
available as text (only as a compiled `.exe`), so it isn't part of this
`.cpp` file. If you still have the newer source file, it's worth adding
here too so the repo reflects the exact version that was graded.

## License

Academic project for educational purposes (UNIMAS, KMK1093).
