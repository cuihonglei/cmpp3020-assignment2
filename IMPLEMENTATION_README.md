# SAIT Enrollment Management System - Implementation Guide

## Overview
This project contains implementations of a student enrollment management system in two different programming languages:
- **C++** (Part 2) - `enrollment_system.cpp`
- **Python** (Part 3) - `enrollment_system.py`

Both implementations follow the pseudocode algorithm defined in Part 1 and provide identical functionality.

## Author
Altesse Imena

## Features
- Add new student records with auto-generated student IDs
- Modify existing student records
- Remove student records
- Display individual student information
- Display all student records
- Input validation for all fields
- Dual data structure approach (list + dictionary) for efficient operations

## Student Information Fields
Each student record contains:
- Student ID (auto-generated, starting from 100001)
- First Name
- Last Name
- Date of Birth (YYYY-MM-DD format)
- Gender
- GPA (0.0 - 4.0)
- Current Semester
- Program
- Number of Courses

## Part 2: C++ Implementation

### Compilation
To compile the C++ program, use one of the following commands:

```bash
# Using g++
g++ -std=c++11 -o enrollment_system enrollment_system.cpp

# Using clang++ (macOS)
clang++ -std=c++11 -o enrollment_system enrollment_system.cpp
```

### Running the C++ Program
```bash
./enrollment_system
```

### Key Programming Concepts Demonstrated (C++)
- **Static Typing**: All variable types are declared at compile time
- **Data Structures**: 
  - `vector<Student>` - dynamic array for storing all records
  - `map<int, Student*>` - dictionary for quick ID-based lookup
  - `struct Student` - composite data type
- **Scoping**: Local variables in functions, global variables for shared state
- **Referencing**: Pointers used to reference students in the map
- **Pass by Value/Reference**: Function parameters demonstrate both approaches
- **Subprograms**: Modular functions for each operation
- **Conditional Statements**: if-else and switch-case for branching
- **Loops**: for loops, while loops, range-based for loops
- **Input Validation**: Error checking for all user inputs

## Part 3: Python Implementation

### Running the Python Program
```bash
python3 enrollment_system.py
```

### Key Programming Concepts Demonstrated (Python)
- **Dynamic Typing**: Types are determined at runtime
- **Data Structures**:
  - `list` - dynamic array for storing all records
  - `dict` - dictionary for quick ID-based lookup
  - Nested dictionaries for student records
- **Scoping**: Function-level scoping with global keyword for shared state
- **Referencing**: Python passes mutable objects (dicts, lists) by reference
- **Subprograms**: Functions for each operation
- **Conditional Statements**: if-elif-else chains for branching
- **Loops**: for-each loops for iteration
- **Exception Handling**: try-except blocks for input validation

## Comparison: C++ vs Python

| Aspect | C++ | Python |
|--------|-----|--------|
| Typing | Static (compile-time) | Dynamic (runtime) |
| Memory Management | Manual (pointers) | Automatic (garbage collection) |
| Compilation | Required | Interpreted |
| Syntax | More verbose | More concise |
| Performance | Faster execution | Slower execution |
| Type Safety | Compile-time checks | Runtime checks |

## Testing the Programs

### Test Scenario 1: Adding Students
1. Run the program
2. Select option 1 (Add Student Record)
3. Enter student information
4. Verify the student ID is assigned correctly
5. Repeat to add multiple students

### Test Scenario 2: Modifying Records
1. Add at least one student
2. Select option 2 (Modify Student Record)
3. Enter the student ID
4. Choose a field to modify
5. Verify the change is reflected when displaying the student

### Test Scenario 3: Removing Records
1. Add multiple students
2. Select option 3 (Remove Student Record)
3. Enter a student ID to remove
4. Verify the student is removed from the list

### Test Scenario 4: Display Operations
1. Add several students
2. Test option 4 (Display Student Record) with valid and invalid IDs
3. Test option 5 (Display All Student Records)
4. Verify all information is displayed correctly

### Test Scenario 5: Input Validation
1. Try entering invalid data types (letters for numbers)
2. Try entering out-of-range values (GPA > 4.0)
3. Verify error messages are displayed and re-prompts occur

## Code Attribution
All code in both implementations was written by **Altesse Imena** as part of CMPP 3020 Assignment 2.
The code follows the pseudocode algorithm developed in Part 1 of the assignment.

## Notes
- Both implementations produce identical output for the same inputs
- Student IDs start at 100001 and auto-increment
- Data is not persisted between program runs (in-memory only)
- Input validation ensures data integrity
- The programs use dual data structures (list + dictionary) for optimal performance in different operations
