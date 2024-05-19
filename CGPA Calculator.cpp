#include <iostream>
#include <iomanip>
#include <cstdlib> // Include this header for exit()

using namespace std;

class Student {
private:
    string _name;
    string _rollNo;
    int _semester;

public:
    void setStudentData() {
        cout << "Enter your name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, _name);

        cout << "Enter your University Roll-No: ";
        getline(cin, _rollNo);

        cout << "Enter your current semester: ";
        cin >> _semester;
    }

    void printStudentData() {
    	cout << "\n----------Result Card-----------\n";
        cout << "\nStudent name: " << _name << endl;
        cout << "Student BZU Roll-No: " << _rollNo << endl;
        cout << "Semester: " << _semester << endl;
        
    }
};

class Cgpa {
private:
    int _totalSubjects;
    float _subjectGPA;
    double _totalGPA = 0.0;

public:
    void getMarks() {
        cout << "Enter your total subjects: ";
        cin >> _totalSubjects;

        for (int i = 1; i <= _totalSubjects; ++i) {
            do {
                cout << "Enter GPA for subject " << i << ": ";
                cin >> _subjectGPA;

                // Validate GPA (assuming it's within the range [0, 4])
                if (_subjectGPA < 0.0 || _subjectGPA > 4.0) {
                    cout << "Invalid GPA. Please enter a value between 0 and 4." << endl;
                }
            } while (_subjectGPA < 0.0 || _subjectGPA > 4.0);

            _totalGPA += _subjectGPA; // Add valid GPA to the total
        }
    }

    void calculateCGPA() {
        double totalGP = _totalGPA / _totalSubjects;
        cout << "Total Obtained GPA: " << _totalGPA << endl;
        cout << fixed << setprecision(2); // Precision to 2 decimal places
        cout << "CGPA = " << totalGP << "\n";
        cout << "\nCalculated Successfully\n";
    }
};

int main() {
    cout << "+------------------------------------------------------+\n";
    cout << "'                                                      '\n";
    cout << "'                    CGPA-Calculator                   '\n";
    cout << "'                                                      '\n";
    cout << "+------------------------------------------------------+\n\n";

while (true) {
        int choice;
        cout << "\nMENU : " << endl;
        cout << "1. Enter Application ?" << endl;
        cout << "2. Exit Application ?" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
            	system("cls");
            	cout << "Calculating....\n";
                Student obj1;
                obj1.setStudentData();
                Cgpa obj2;
                obj2.getMarks();
                system("cls");
                obj1.printStudentData();
                obj2.calculateCGPA();
                break;
            }
            case 2:
            	system("cls");
                cout << "Exiting the application...." << endl;
                exit(EXIT_SUCCESS); // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
