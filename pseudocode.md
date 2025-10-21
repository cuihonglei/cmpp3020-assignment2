# Subprogram: Add Student Record
```plaintext
SUBPROGRAM add_student()
    DECLARE student AS DICTIONARY

    # Assign a unique Student ID automatically
    student["id"] = next_student_id
    next_student_id = next_student_id + 1
    
    PRINT "Enter First Name: "
    INPUT student["first_name"]

    PRINT "Enter Last Name: "
    INPUT student["last_name"]

    PRINT "Enter Date of Birth (YYYY-MM-DD): "
    INPUT student["date_of_birth"]

    PRINT "Enter Gender: "
    INPUT student["gender"]

    PRINT "Enter GPA from Previous Institution: "
    INPUT student["gpa"]

    PRINT "Enter Current Semester: "
    INPUT student["semester"]

    PRINT "Enter Program: "
    INPUT student["program"]

    PRINT "Enter Number of Courses: "
    INPUT student["num_courses"]

    # Save student record in both structures
    APPEND student TO student_records
    student_dict[student["id"]] = student

    PRINT "Student record added successfully. Assigned Student ID: ", student["id"]
END SUBPROGRAM
```

# Subprogram: Modify Student Record
```plaintext
SUBPROGRAM modify_student()
    PRINT "Enter Student ID to modify: "
    INPUT search_id

    # Check if the student ID exists in the dictionary
    IF search_id IN student_dict THEN
        DECLARE student AS DICTIONARY = student_dict[search_id]
        PRINT "Record found for ID ", student["id"], ": ", student["first_name"], " ", student["last_name"]

        PRINT "Select field to modify:"
        PRINT "1. First Name"
        PRINT "2. Last Name"
        PRINT "3. Date of Birth"
        PRINT "4. Gender"
        PRINT "5. GPA"
        PRINT "6. Semester"
        PRINT "7. Program"
        PRINT "8. Number of Courses"
        INPUT choice

        SWITCH(choice)
            CASE 1: PRINT "Enter new First Name: "; INPUT student["first_name"]
            CASE 2: PRINT "Enter new Last Name: "; INPUT student["last_name"]
            CASE 3: PRINT "Enter new Date of Birth: "; INPUT student["date_of_birth"]
            CASE 4: PRINT "Enter new Gender: "; INPUT student["gender"]
            CASE 5: PRINT "Enter new GPA: "; INPUT student["gpa"]
            CASE 6: PRINT "Enter new Semester: "; INPUT student["semester"]
            CASE 7: PRINT "Enter new Program: "; INPUT student["program"]
            CASE 8: PRINT "Enter new Number of Courses: "; INPUT student["num_courses"]
            DEFAULT: 
                PRINT "Invalid choice."
                EXIT # Exit the subprogram immediately
        END SWITCH

        PRINT "Record updated successfully."
    ELSE
        PRINT "No record found with that Student ID."
    END IF
END SUBPROGRAM
```

# Subprogram: Remove Student Record
```plaintext
SUBPROGRAM remove_student()
    PRINT "Enter Student ID of the student to remove: "
    INPUT search_id

    # Check if Student ID exists
    IF search_id IN student_dict THEN
        DECLARE student AS DICTIONARY = student_dict[search_id]
        REMOVE student FROM student_records
        REMOVE student_dict[search_id]
        PRINT "Student record with ID ", search_id, " removed successfully."
    ELSE
        PRINT "No student found with that Student ID."
    END IF
END SUBPROGRAM
```

# Subprogram: Display Student
```plaintext
SUBPROGRAM display_student()
    PRINT "Enter Student ID to display: "
    INPUT search_id

    # Check if the student exists in the dictionary
    IF search_id IN student_dict THEN
        DECLARE student AS DICTIONARY = student_dict[search_id]
        PRINT "----- Student Information -----"
        PRINT "Student ID: ", student["id"]
        PRINT "Name: ", student["first_name"], " ", student["last_name"]
        PRINT "DOB: ", student["date_of_birth"]
        PRINT "Gender: ", student["gender"]
        PRINT "GPA: ", student["gpa"]
        PRINT "Semester: ", student["semester"]
        PRINT "Program: ", student["program"]
        PRINT "Courses: ", student["num_courses"]
        PRINT "-------------------------------"
    ELSE
        PRINT "No student found with that Student ID."
    END IF
END SUBPROGRAM
```

# Subprogram: Display All Students
```plaintext
SUBPROGRAM display_all_students()
    IF LENGTH(student_records) == 0 THEN
        PRINT "No student records found."
    ELSE
        PRINT "----- Student Records -----"
        FOR EACH student IN student_records
            PRINT "Name: ", student["first_name"], " ", student["last_name"]
            PRINT "DOB: ", student["date_of_birth"]
            PRINT "Gender: ", student["gender"]
            PRINT "GPA: ", student["gpa"]
            PRINT "Semester: ", student["semester"]
            PRINT "Program: ", student["program"]
            PRINT "Courses: ", student["num_courses"]
            PRINT "----------------------------"
        END FOR
    END IF
END SUBPROGRAM
```

# Subprogram: Display Menu
```plaintext
SUBPROGRAM display_menu()
    PRINT "===== SAIT Enrollment Management System ====="
    PRINT "1. Add Student Record"
    PRINT "2. Modify Student Record"
    PRINT "3. Remove Student Record"
    PRINT "4. Display Student Record"
    PRINT "5. Display All Student Records"
    PRINT "6. Exit System"
END SUBPROGRAM
```

# Main Program Logic
```plaintext
PROGRAM ENROLLMENT_MANAGEMENT_SYSTEM  

    # The program manages student enrollment information
    # Each student has an auto-generated Student ID
    # Student records are stored in both:
    # 1. A LIST (student_records) for displaying all students
    # 2. A DICTIONARY (student_dict) for quick lookup by Student ID

    DECLARE student_records AS LIST
    DECLARE student_dict AS DICTIONARY
    DECLARE next_student_id AS INTEGER = 100001 # Used to auto-generate unique Student IDs

    REPEAT
        CALL display_menu()
        PRINT "Enter your choice: "
        INPUT choice

        SWITCH(choice)
            CASE 1: CALL add_student()
            CASE 2: CALL modify_student()
            CASE 3: CALL remove_student()
            CASE 4: CALL display_student()
            CASE 5: CALL display_all_students()
            CASE 6: PRINT "Exiting system... Goodbye!"
            DEFAULT: PRINT "Invalid option. Please try again."
        END SWITCH

    UNTIL choice == 6
END PROGRAM
```