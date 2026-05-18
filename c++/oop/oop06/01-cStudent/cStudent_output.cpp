// cStudent_output.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"

void cStudent::output() const {
    cout << "ID: " << studentID 
         << " | Name: " << fullName 
         << " | Address: " << address 
         << " | Credits: " << totalCredits 
         << " | Avg Score: " << averageScore;
}

void cCollegeStudent::output() const {
    cout << "[COLLEGE] ";
    cStudent::output();
    cout << " | Exam Score: " << graduationExamScore << endl;
}

void cUniversityStudent::output() const {
    cout << "[UNIVERSITY] ";
    cStudent::output();
    cout << " | Thesis: " << thesisName 
         << " | Thesis Score: " << thesisScore << endl;
}

// Operator Overloading applied to output via Polymorphism
ostream& operator<<(ostream& os, const cStudent& st) {
    st.output(); 
    return os;
}