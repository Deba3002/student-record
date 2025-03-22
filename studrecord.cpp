#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int roll_no;
    string name;
    float marks;

public:
    // Constructor
    Student(int r, string n, float m) {
        roll_no = r;
        name = n;
        marks = m;
    }

    // Display student details
    void display() {
        cout << "Roll No: " << roll_no << ", Name: " << name << ", Marks: " << marks << endl;
    }

    // Getters
    int getRollNo() { return roll_no; }
    string getName() { return name; }
    float getMarks() { return marks; }

    // Setters (for updating)
    void setName(string n) { name = n; }
    void setMarks(float m) { marks = m; }
};

// Function prototypes
void addStudent(vector<Student> &students);
void displayStudents(const vector<Student> &students);
void searchStudent(const vector<Student> &students, int roll_no);
void deleteStudent(vector<Student> &students, int roll_no);
void updateStudent(vector<Student> &students, int roll_no);

int main() {
    vector<Student> students;
    int choice, roll_no;

    while (true) {
        cout << "\nStudent Record Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
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
                cout << "Enter roll number to search: ";
                cin >> roll_no;
                searchStudent(students, roll_no);
                break;
            case 4:
                cout << "Enter roll number to update: ";
                cin >> roll_no;
                updateStudent(students, roll_no);
                break;
            case 5:
                cout << "Enter roll number to delete: ";
                cin >> roll_no;
                deleteStudent(students, roll_no);
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Function to add a student
void addStudent(vector<Student> &students) {
    int roll_no;
    string name;
    float marks;

    cout << "Enter roll number: ";
    cin >> roll_no;
    cin.ignore(); // To clear buffer
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter marks: ";
    cin >> marks;

    students.push_back(Student(roll_no, name, marks));
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No student records found!\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (const auto &student : students) {
        student.display();
    }
}

// Function to search for a student
void searchStudent(const vector<Student> &students, int roll_no) {
    for (const auto &student : students) {
        if (student.getRollNo() == roll_no) {
            cout << "Student Found:\n";
            student.display();
            return;
        }
    }
    cout << "Student with Roll No " << roll_no << " not found!\n";
}

// Function to update student details
void updateStudent(vector<Student> &students, int roll_no) {
    for (auto &student : students) {
        if (student.getRollNo() == roll_no) {
            string new_name;
            float new_marks;

            cin.ignore(); // Clear buffer
            cout << "Enter new name: ";
            getline(cin, new_name);
            cout << "Enter new marks: ";
            cin >> new_marks;

            student.setName(new_name);
            student.setMarks(new_marks);
            cout << "Student record updated successfully!\n";
            return;
        }
    }
    cout << "Student with Roll No " << roll_no << " not found!\n";
}

// Function to delete a student
void deleteStudent(vector<Student> &students, int roll_no) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getRollNo() == roll_no) {
            students.erase(it);
            cout << "Student record deleted successfully!\n";
            return;
        }
    }
    cout << "Student with Roll No " << roll_no << " not found!\n";
}
