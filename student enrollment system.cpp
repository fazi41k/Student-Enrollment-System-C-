#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store student details
struct Student {
    int rollNo;
    string name;
    string course;
    int year;
};

// Function to add a new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNo;
    cin.ignore(); // To handle newline character in input buffer
    cout << "Enter Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Course: ";
    getline(cin, newStudent.course);
    cout << "Enter Year of Enrollment: ";
    cin >> newStudent.year;

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students enrolled yet.\n";
        return;
    }

    cout << "\nEnrolled Students:\n";
    for (const auto& student : students) {
        cout << "Roll Number: " << student.rollNo << endl;
        cout << "Name: " << student.name << endl;
        cout << "Course: " << student.course << endl;
        cout << "Year: " << student.year << endl;
        cout << "--------------------------\n";
    }
}

// Function to search for a student by roll number
void searchStudent(const vector<Student>& students) {
    int rollNo;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNo;

    for (const auto& student : students) {
        if (student.rollNo == rollNo) {
            cout << "\nStudent Found:\n";
            cout << "Roll Number: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Course: " << student.course << endl;
            cout << "Year: " << student.year << endl;
            return;
        }
    }
    cout << "Student with Roll Number " << rollNo << " not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Enrollment System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
