// cStudent_input.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"

void cStudent::input() {
    cout << "Enter Student ID: ";
    cin >> studentID;
    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Total Credits: ";
    cin >> totalCredits;
    cout << "Enter Average Score: ";
    cin >> averageScore;
}

void cCollegeStudent::input() {
    cout << "\n--- College Student Input ---\n";
    cStudent::input();
    cout << "Enter Graduation Exam Score: ";
    cin >> graduationExamScore;
}

void cUniversityStudent::input() {
    cout << "\n--- University Student Input ---\n";
    cStudent::input();
    cin.ignore();
    cout << "Enter Thesis Name: ";
    getline(cin, thesisName);
    cout << "Enter Thesis Score: ";
    cin >> thesisScore;
}

// Operator Overloading applied to input via Polymorphism
istream& operator>>(istream& is, cStudent& st) {
    st.input(); 
    return is;
}