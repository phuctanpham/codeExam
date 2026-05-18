// cStudents_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"

// --- cStudent Base Methods ---
string cStudent::getStudentID() const { return studentID; }
void cStudent::setStudentID(const string& id) { studentID = id; }

string cStudent::getFullName() const { return fullName; }
void cStudent::setFullName(const string& name) { fullName = name; }

string cStudent::getAddress() const { return address; }
void cStudent::setAddress(const string& addr) { address = addr; }

int cStudent::getTotalCredits() const { return totalCredits; }
void cStudent::setTotalCredits(int credits) { totalCredits = credits; }

float cStudent::getAverageScore() const { return averageScore; }
void cStudent::setAverageScore(float score) { averageScore = score; }

// --- cCollegeStudent Methods ---
float cCollegeStudent::getGraduationExamScore() const { return graduationExamScore; }
void cCollegeStudent::setGraduationExamScore(float score) { graduationExamScore = score; }

bool cCollegeStudent::isEligibleForGraduation() const {
    return (totalCredits >= 110 && averageScore >= 5.0f && graduationExamScore >= 5.0f);
}

// --- cUniversityStudent Methods ---
string cUniversityStudent::getThesisName() const { return thesisName; }
void cUniversityStudent::setThesisName(const string& thesis) { thesisName = thesis; }

float cUniversityStudent::getThesisScore() const { return thesisScore; }
void cUniversityStudent::setThesisScore(float score) { thesisScore = score; }

bool cUniversityStudent::isEligibleForGraduation() const {
    return (totalCredits >= 145 && averageScore >= 5.0f && thesisScore >= 5.0f);
}