#include "database.h"
#include "student.h"
#include <iostream>

int main() {
    connectToDB();

    int choice;
    do {
        std::cout << "\n--- Student Management System ---\n";
        std::cout << "1. Add Student\n2. View Students\n3. Update Student\n4. Delete Student\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 0: break;
            default: std::cout << "Invalid choice\n";
        }

    } while (choice != 0);

    closeDB();
    return 0;
}
