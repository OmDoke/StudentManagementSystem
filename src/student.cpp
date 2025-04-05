#include "student.h"
#include "database.h"
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <iostream>

void addStudent() {
    std::string name;
    int age;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter age: ";
    std::cin >> age;

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("INSERT INTO students (name, age) VALUES (?, ?)")
        );
        pstmt->setString(1, name);
        pstmt->setInt(2, age);
        pstmt->execute();
        std::cout << "Student added.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "Error adding student: " << e.what() << std::endl;
    }
}

void viewStudents() {
    try {
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM students"));

        std::cout << "ID\tName\tAge\n";
        while (res->next()) {
            std::cout << res->getInt("id") << "\t" << res->getString("name") << "\t" << res->getInt("age") << "\n";
        }
    } catch (sql::SQLException &e) {
        std::cerr << "Error viewing students: " << e.what() << std::endl;
    }
}

void updateStudent() {
    int id, age;
    std::string name;
    std::cout << "Enter ID to update: ";
    std::cin >> id;
    std::cout << "Enter new name: ";
    std::cin >> name;
    std::cout << "Enter new age: ";
    std::cin >> age;

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("UPDATE students SET name=?, age=? WHERE id=?")
        );
        pstmt->setString(1, name);
        pstmt->setInt(2, age);
        pstmt->setInt(3, id);
        pstmt->execute();
        std::cout << "Student updated.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "Error updating student: " << e.what() << std::endl;
    }
}

void deleteStudent() {
    int id;
    std::cout << "Enter ID to delete: ";
    std::cin >> id;

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->prepareStatement("DELETE FROM students WHERE id=?")
        );
        pstmt->setInt(1, id);
        pstmt->execute();
        std::cout << "Student deleted.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "Error deleting student: " << e.what() << std::endl;
    }
}
