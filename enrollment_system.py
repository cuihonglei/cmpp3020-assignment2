"""
SAIT Enrollment Management System - Python Implementation
Part 3 of Assignment 2

This program implements a student enrollment management system that allows
administrative staff to add, modify, remove, and display student records.

This Python implementation replicates the functionality of the C++ version
developed in Part 2, demonstrating how the same algorithm can be implemented
in different programming languages with different typing systems and syntax.

Author: Altesse Imena
Date: October 23, 2025
"""

# Global variables for student data management
# Python uses dynamic typing - types are determined at runtime
student_records = []  # List to store all student records (dynamic array)
student_dict = {}     # Dictionary for quick lookup by student ID
next_student_id = 100001  # Auto-incrementing student ID counter


def display_menu():
    """
    Displays the main menu options
    Subprogram with no parameters (demonstrates modular design)
    Author: Altesse Imena
    """
    print("===== SAIT Enrollment Management System =====")
    print("1. Add Student Record")
    print("2. Modify Student Record")
    print("3. Remove Student Record")
    print("4. Display Student Record")
    print("5. Display All Student Records")
    print("6. Exit System")


def add_student():
    """
    Adds a new student record to the system
    Demonstrates dynamic typing and use of dictionaries
    Uses global variables to maintain state across function calls
    Author: Altesse Imena
    """
    global next_student_id  # Access global variable for modification
    
    # Create student dictionary to hold all information
    # Python dictionaries provide dynamic key-value storage
    student = {}
    
    # Assign unique student ID (auto-increment)
    student["id"] = next_student_id
    next_student_id += 1  # Increment for next student
    
    # Collect student information with input prompts
    student["first_name"] = input("Enter First Name: ")
    student["last_name"] = input("Enter Last Name: ")
    student["date_of_birth"] = input("Enter Date of Birth (YYYY-MM-DD): ")
    student["gender"] = input("Enter Gender: ")
    
    # Input validation for GPA (must be numeric and in valid range)
    while True:
        try:
            gpa = float(input("Enter GPA from Previous Institution: "))
            if 0.0 <= gpa <= 4.0:
                student["gpa"] = gpa
                break
            else:
                print("Invalid GPA. Please enter a value between 0.0 and 4.0.")
        except ValueError:
            print("Invalid input. Please enter a numeric value.")
    
    # Input validation for semester (must be positive integer)
    while True:
        try:
            semester = int(input("Enter Current Semester: "))
            if semester >= 1:
                student["semester"] = semester
                break
            else:
                print("Invalid semester. Please enter a positive number.")
        except ValueError:
            print("Invalid input. Please enter an integer.")
    
    student["program"] = input("Enter Program: ")
    
    # Input validation for number of courses
    while True:
        try:
            num_courses = int(input("Enter Number of Courses: "))
            if num_courses >= 0:
                student["num_courses"] = num_courses
                break
            else:
                print("Invalid number. Please enter a non-negative number.")
        except ValueError:
            print("Invalid input. Please enter an integer.")
    
    # Store student record in list
    student_records.append(student)
    
    # Store reference to student in dictionary for quick lookup
    # Python dictionaries store references to objects
    student_dict[student["id"]] = student
    
    print(f"Student record added successfully. Assigned Student ID: {student['id']}")


def modify_student():
    """
    Modifies an existing student record
    Demonstrates use of references and conditional statements
    Python passes mutable objects (like dictionaries) by reference
    Author: Altesse Imena
    """
    # Input validation for student ID
    try:
        search_id = int(input("Enter Student ID to modify: "))
    except ValueError:
        print("Invalid input.")
        return
    
    # Check if student ID exists in the dictionary
    if search_id in student_dict:
        # Get reference to student dictionary
        student = student_dict[search_id]
        
        print(f"Record found for ID {student['id']}: {student['first_name']} {student['last_name']}")
        
        # Display modification menu
        print("Select field to modify:")
        print("1. First Name")
        print("2. Last Name")
        print("3. Date of Birth")
        print("4. Gender")
        print("5. GPA")
        print("6. Semester")
        print("7. Program")
        print("8. Number of Courses")
        
        try:
            choice = int(input("Enter choice: "))
        except ValueError:
            print("Invalid input.")
            return
        
        # Conditional statements to handle different field modifications
        # Demonstrates branching logic
        if choice == 1:
            student["first_name"] = input("Enter new First Name: ")
        elif choice == 2:
            student["last_name"] = input("Enter new Last Name: ")
        elif choice == 3:
            student["date_of_birth"] = input("Enter new Date of Birth: ")
        elif choice == 4:
            student["gender"] = input("Enter new Gender: ")
        elif choice == 5:
            # Input validation for GPA
            while True:
                try:
                    gpa = float(input("Enter new GPA: "))
                    if 0.0 <= gpa <= 4.0:
                        student["gpa"] = gpa
                        break
                    else:
                        print("Invalid GPA. Please enter a value between 0.0 and 4.0.")
                except ValueError:
                    print("Invalid input. Please enter a numeric value.")
        elif choice == 6:
            # Input validation for semester
            while True:
                try:
                    semester = int(input("Enter new Semester: "))
                    if semester >= 1:
                        student["semester"] = semester
                        break
                    else:
                        print("Invalid semester. Please enter a positive number.")
                except ValueError:
                    print("Invalid input. Please enter an integer.")
        elif choice == 7:
            student["program"] = input("Enter new Program: ")
        elif choice == 8:
            # Input validation for number of courses
            while True:
                try:
                    num_courses = int(input("Enter new Number of Courses: "))
                    if num_courses >= 0:
                        student["num_courses"] = num_courses
                        break
                    else:
                        print("Invalid number. Please enter a non-negative number.")
                except ValueError:
                    print("Invalid input. Please enter an integer.")
        else:
            print("Invalid choice.")
            return
        
        print("Record updated successfully.")
    else:
        print("No record found with that Student ID.")


def remove_student():
    """
    Removes a student record from the system
    Demonstrates list and dictionary manipulation
    Author: Altesse Imena
    """
    # Input validation for student ID
    try:
        search_id = int(input("Enter Student ID of the student to remove: "))
    except ValueError:
        print("Invalid input.")
        return
    
    # Check if student ID exists
    if search_id in student_dict:
        # Get reference to student
        student = student_dict[search_id]
        
        # Remove from list using remove method
        student_records.remove(student)
        
        # Remove from dictionary
        del student_dict[search_id]
        
        print(f"Student record with ID {search_id} removed successfully.")
    else:
        print("No student found with that Student ID.")


def display_student():
    """
    Displays a single student record
    Demonstrates formatted output and conditional statements
    Author: Altesse Imena
    """
    # Input validation for student ID
    try:
        search_id = int(input("Enter Student ID to display: "))
    except ValueError:
        print("Invalid input.")
        return
    
    # Check if student exists in dictionary
    if search_id in student_dict:
        student = student_dict[search_id]
        
        # Display formatted student information
        print("----- Student Information -----")
        print(f"Student ID: {student['id']}")
        print(f"Name: {student['first_name']} {student['last_name']}")
        print(f"DOB: {student['date_of_birth']}")
        print(f"Gender: {student['gender']}")
        print(f"GPA: {student['gpa']:.2f}")  # Format to 2 decimal places
        print(f"Semester: {student['semester']}")
        print(f"Program: {student['program']}")
        print(f"Courses: {student['num_courses']}")
        print("-------------------------------")
    else:
        print("No student found with that Student ID.")


def display_all_students():
    """
    Displays all student records in the system
    Demonstrates use of loops (for-each) and conditional statements
    Author: Altesse Imena
    """
    # Check if there are any records
    if len(student_records) == 0:
        print("No student records found.")
        return
    
    print("----- Student Records -----")
    
    # Iterate through all students using for-each loop
    # Demonstrates iteration over a list
    for student in student_records:
        print(f"Student ID: {student['id']}")
        print(f"Name: {student['first_name']} {student['last_name']}")
        print(f"DOB: {student['date_of_birth']}")
        print(f"Gender: {student['gender']}")
        print(f"GPA: {student['gpa']:.2f}")
        print(f"Semester: {student['semester']}")
        print(f"Program: {student['program']}")
        print(f"Courses: {student['num_courses']}")
        print("----------------------------")


def main():
    """
    Main program entry point
    Implements the main menu loop for the enrollment system
    Author: Altesse Imena
    """
    running = True  # Control variable for main loop
    
    # Main program loop - continues until user chooses to exit
    while running:
        display_menu()
        
        # Input validation for menu choice
        try:
            choice = int(input("Enter your choice: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
            print()
            continue
        
        # Conditional statements for menu navigation (demonstrates branching)
        # Python doesn't have switch statements (until 3.10 match-case)
        # Using if-elif-else chain instead
        if choice == 1:
            add_student()  # Call subprogram to add student
        elif choice == 2:
            modify_student()  # Call subprogram to modify student
        elif choice == 3:
            remove_student()  # Call subprogram to remove student
        elif choice == 4:
            display_student()  # Call subprogram to display single student
        elif choice == 5:
            display_all_students()  # Call subprogram to display all students
        elif choice == 6:
            print("Exiting system... Goodbye!")
            running = False  # Exit the loop
        else:
            print("Invalid option. Please try again.")
        
        print()  # Add spacing between operations


# Entry point for the program
# This ensures the main function only runs when the script is executed directly
if __name__ == "__main__":
    main()
