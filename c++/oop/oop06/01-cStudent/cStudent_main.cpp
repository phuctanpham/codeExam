// cStudent_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"

int main() {
    vector<cStudent*> students;
    int nC, nU;

    // 1. Input lists
    cout << "Enter number of College Students: ";
    cin >> nC;
    for (int i = 0; i < nC; ++i) {
        cStudent* s = new cCollegeStudent();
        cin >> *s; // Polymorphic operator>>
        students.push_back(s);
    }

    cout << "\nEnter number of University Students: ";
    cin >> nU;
    for (int i = 0; i < nU; ++i) {
        cStudent* s = new cUniversityStudent();
        cin >> *s;
        students.push_back(s);
    }

    // 2. Process and output lists
    cout << "\n=== ALL STUDENTS ===\n";
    for (const auto& s : students) {
        cout << *s; 
    }

    cout << "\n=== ELIGIBLE FOR GRADUATION ===\n";
    for (const auto& s : students) {
        if (s->isEligibleForGraduation()) { // Polymorphic call
            cout << *s;
        }
    }

    cout << "\n=== NOT ELIGIBLE FOR GRADUATION ===\n";
    for (const auto& s : students) {
        if (!s->isEligibleForGraduation()) {
            cout << *s;
        }
    }

    // 3. Identify highest average score among university students
    cout << "\n=== UNIVERSITY STUDENT WITH HIGHEST AVG SCORE ===\n";
    float maxScore = -1.0f;
    cUniversityStudent* topUniStudent = nullptr;
    
    for (const auto& s : students) {
        // RTTI dynamically casts base to derived to ensure safety
        if (cUniversityStudent* u = dynamic_cast<cUniversityStudent*>(s)) {
            if (u->getAverageScore() > maxScore) {
                maxScore = u->getAverageScore();
                topUniStudent = u;
            }
        }
    }

    if (topUniStudent) {
        cout << *topUniStudent; // Triggers overloaded operator<<
    } else {
        cout << "No university students found.\n";
    }

    // 4. Lean Memory Management Cleanup
    for (auto& s : students) {
        delete s;
    }
    students.clear();

    return 0;
}