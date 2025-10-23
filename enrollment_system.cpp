/*
 * SAIT Enrollment Management System - C++ Implementation
 * Part 2 of Assignment 2
 * 
 * This program implements a student enrollment management system that allows
 * administrative staff to add, modify, remove, and display student records.
 * 
 * Author: Altesse Imena
 * Date: October 23, 2025
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Student structure to hold all student information
// Demonstrates use of various data types (string, int, double)
struct Student {
    int id;                    // Unique student ID (static binding - type known at compile time)
    string first_name;         // Student's first name
    string last_name;          // Student's last name
    string date_of_birth;      // Date of birth in YYYY-MM-DD format
    string gender;             // Student's gender
    double gpa;                // GPA from previous institution (double for precision)
    int semester;              // Current semester number
    string program;            // Academic program name
    int num_courses;           // Number of courses enrolled
};

// Global variables for student data management
// Demonstrates static data binding (types known at compile time)
vector<Student> student_records;           // Dynamic array (list) to store all student records
map<int, Student*> student_dict;           // Dictionary (map) for quick lookup by ID using references
int next_student_id = 100001;              // Auto-incrementing student ID counter

// Function prototypes (forward declarations)
void display_menu();
void add_student();
void modify_student();
void remove_student();
void display_student();
void display_all_students();
void clear_input_buffer();

/*
 * Main program entry point
 * Implements the main menu loop for the enrollment system
 * Author: Altesse Imena
 */
int main() {
    int choice;  // Local variable with block scope
    bool running = true;  // Control variable for main loop
    
    // Main program loop - continues until user chooses to exit
    while (running) {
        display_menu();
        cout << "Enter your choice: ";
        
        // Input validation to handle non-integer input
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            clear_input_buffer();
            continue;
        }
        
        clear_input_buffer();  // Clear remaining newline character
        
        // Switch statement for menu navigation (demonstrates branching)
        switch (choice) {
            case 1:
                add_student();  // Call subprogram to add student
                break;
            case 2:
                modify_student();  // Call subprogram to modify student
                break;
            case 3:
                remove_student();  // Call subprogram to remove student
                break;
            case 4:
                display_student();  // Call subprogram to display single student
                break;
            case 5:
                display_all_students();  // Call subprogram to display all students
                break;
            case 6:
                cout << "Exiting system... Goodbye!" << endl;
                running = false;  // Exit the loop
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        
        cout << endl;  // Add spacing between operations
    }
    
    return 0;
}

/*
 * Displays the main menu options
 * Subprogram with no parameters (demonstrates modular design)
 * Author: Altesse Imena
 */
void display_menu() {
    cout << "===== SAIT Enrollment Management System =====" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. Modify Student Record" << endl;
    cout << "3. Remove Student Record" << endl;
    cout << "4. Display Student Record" << endl;
    cout << "5. Display All Student Records" << endl;
    cout << "6. Exit System" << endl;
}

/*
 * Adds a new student record to the system
 * Demonstrates pass by value for primitive types and use of references
 * Author: Altesse Imena
 */
void add_student() {
    Student student;  // Local variable - demonstrates block scoping
    
    // Assign unique student ID (auto-increment)
    student.id = next_student_id;
    next_student_id++;  // Increment for next student
    
    // Collect student information with input prompts
    cout << "Enter First Name: ";
    getline(cin, student.first_name);
    
    cout << "Enter Last Name: ";
    getline(cin, student.last_name);
    
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    getline(cin, student.date_of_birth);
    
    cout << "Enter Gender: ";
    getline(cin, student.gender);
    
    // Input validation for GPA (must be numeric)
    cout << "Enter GPA from Previous Institution: ";
    while (!(cin >> student.gpa) || student.gpa < 0.0 || student.gpa > 4.0) {
        cout << "Invalid GPA. Please enter a value between 0.0 and 4.0: ";
        clear_input_buffer();
    }
    clear_input_buffer();
    
    // Input validation for semester (must be positive integer)
    cout << "Enter Current Semester: ";
    while (!(cin >> student.semester) || student.semester < 1) {
        cout << "Invalid semester. Please enter a positive number: ";
        clear_input_buffer();
    }
    clear_input_buffer();
    
    cout << "Enter Program: ";
    getline(cin, student.program);
    
    // Input validation for number of courses
    cout << "Enter Number of Courses: ";
    while (!(cin >> student.num_courses) || student.num_courses < 0) {
        cout << "Invalid number. Please enter a non-negative number: ";
        clear_input_buffer();
    }
    clear_input_buffer();
    
    // Store student record in vector (list)
    student_records.push_back(student);
    
    // Store reference to student in map (dictionary) for quick lookup
    // Demonstrates use of referencing - storing pointer to the last element
    student_dict[student.id] = &student_records.back();
    
    cout << "Student record added successfully. Assigned Student ID: " << student.id << endl;
}

/*
 * Modifies an existing student record
 * Demonstrates use of references and conditional statements
 * Author: Altesse Imena
 */
void modify_student() {
    int search_id;
    
    cout << "Enter Student ID to modify: ";
    if (!(cin >> search_id)) {
        cout << "Invalid input." << endl;
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    // Check if student ID exists in the dictionary (demonstrates referencing)
    if (student_dict.find(search_id) != student_dict.end()) {
        Student* student = student_dict[search_id];  // Get reference to student
        
        cout << "Record found for ID " << student->id << ": " 
             << student->first_name << " " << student->last_name << endl;
        
        // Display modification menu
        cout << "Select field to modify:" << endl;
        cout << "1. First Name" << endl;
        cout << "2. Last Name" << endl;
        cout << "3. Date of Birth" << endl;
        cout << "4. Gender" << endl;
        cout << "5. GPA" << endl;
        cout << "6. Semester" << endl;
        cout << "7. Program" << endl;
        cout << "8. Number of Courses" << endl;
        
        int choice;
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input." << endl;
            clear_input_buffer();
            return;
        }
        clear_input_buffer();
        
        // Switch statement to handle different field modifications
        // Demonstrates branching and conditional logic
        switch (choice) {
            case 1:
                cout << "Enter new First Name: ";
                getline(cin, student->first_name);
                break;
            case 2:
                cout << "Enter new Last Name: ";
                getline(cin, student->last_name);
                break;
            case 3:
                cout << "Enter new Date of Birth: ";
                getline(cin, student->date_of_birth);
                break;
            case 4:
                cout << "Enter new Gender: ";
                getline(cin, student->gender);
                break;
            case 5:
                cout << "Enter new GPA: ";
                while (!(cin >> student->gpa) || student->gpa < 0.0 || student->gpa > 4.0) {
                    cout << "Invalid GPA. Please enter a value between 0.0 and 4.0: ";
                    clear_input_buffer();
                }
                clear_input_buffer();
                break;
            case 6:
                cout << "Enter new Semester: ";
                while (!(cin >> student->semester) || student->semester < 1) {
                    cout << "Invalid semester. Please enter a positive number: ";
                    clear_input_buffer();
                }
                clear_input_buffer();
                break;
            case 7:
                cout << "Enter new Program: ";
                getline(cin, student->program);
                break;
            case 8:
                cout << "Enter new Number of Courses: ";
                while (!(cin >> student->num_courses) || student->num_courses < 0) {
                    cout << "Invalid number. Please enter a non-negative number: ";
                    clear_input_buffer();
                }
                clear_input_buffer();
                break;
            default:
                cout << "Invalid choice." << endl;
                return;
        }
        
        cout << "Record updated successfully." << endl;
    } else {
        cout << "No record found with that Student ID." << endl;
    }
}

/*
 * Removes a student record from the system
 * Demonstrates use of iterators and container manipulation
 * Author: Altesse Imena
 */
void remove_student() {
    int search_id;
    
    cout << "Enter Student ID of the student to remove: ";
    if (!(cin >> search_id)) {
        cout << "Invalid input." << endl;
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    // Check if student ID exists
    if (student_dict.find(search_id) != student_dict.end()) {
        // Remove from vector using iterator
        // Demonstrates use of loops and conditional logic
        for (auto it = student_records.begin(); it != student_records.end(); ++it) {
            if (it->id == search_id) {
                student_records.erase(it);
                break;
            }
        }
        
        // Remove from dictionary
        student_dict.erase(search_id);
        
        // Update all pointers in the dictionary after vector modification
        // This is necessary because vector elements may have been moved in memory
        student_dict.clear();
        for (size_t i = 0; i < student_records.size(); ++i) {
            student_dict[student_records[i].id] = &student_records[i];
        }
        
        cout << "Student record with ID " << search_id << " removed successfully." << endl;
    } else {
        cout << "No student found with that Student ID." << endl;
    }
}

/*
 * Displays a single student record
 * Demonstrates formatted output and conditional statements
 * Author: Altesse Imena
 */
void display_student() {
    int search_id;
    
    cout << "Enter Student ID to display: ";
    if (!(cin >> search_id)) {
        cout << "Invalid input." << endl;
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    // Check if student exists in dictionary
    if (student_dict.find(search_id) != student_dict.end()) {
        Student* student = student_dict[search_id];
        
        // Display formatted student information
        cout << "----- Student Information -----" << endl;
        cout << "Student ID: " << student->id << endl;
        cout << "Name: " << student->first_name << " " << student->last_name << endl;
        cout << "DOB: " << student->date_of_birth << endl;
        cout << "Gender: " << student->gender << endl;
        cout << fixed << setprecision(2);  // Format GPA to 2 decimal places
        cout << "GPA: " << student->gpa << endl;
        cout << "Semester: " << student->semester << endl;
        cout << "Program: " << student->program << endl;
        cout << "Courses: " << student->num_courses << endl;
        cout << "-------------------------------" << endl;
    } else {
        cout << "No student found with that Student ID." << endl;
    }
}

/*
 * Displays all student records in the system
 * Demonstrates use of loops (for-each) and conditional statements
 * Author: Altesse Imena
 */
void display_all_students() {
    // Check if there are any records
    if (student_records.empty()) {
        cout << "No student records found." << endl;
        return;
    }
    
    cout << "----- Student Records -----" << endl;
    
    // Iterate through all students using range-based for loop
    // Demonstrates use of loops and pass by reference (const reference for efficiency)
    for (const Student& student : student_records) {
        cout << "Student ID: " << student.id << endl;
        cout << "Name: " << student.first_name << " " << student.last_name << endl;
        cout << "DOB: " << student.date_of_birth << endl;
        cout << "Gender: " << student.gender << endl;
        cout << fixed << setprecision(2);
        cout << "GPA: " << student.gpa << endl;
        cout << "Semester: " << student.semester << endl;
        cout << "Program: " << student.program << endl;
        cout << "Courses: " << student.num_courses << endl;
        cout << "----------------------------" << endl;
    }
}

/*
 * Utility function to clear input buffer
 * Prevents input errors from affecting subsequent input operations
 * Author: Altesse Imena
 */
void clear_input_buffer() {
    cin.clear();  // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard remaining input
}
