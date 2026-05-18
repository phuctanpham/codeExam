// cStudents_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cStudent.h"

// --- cStudent Constructors ---
cStudent::cStudent() : studentID(""), fullName(""), address(""), totalCredits(0), averageScore(0.0f) {}

cStudent::cStudent(string id, string name, string addr, int credits, float score)
    : studentID(id), fullName(name), address(addr), totalCredits(credits), averageScore(score) {}

// --- cCollegeStudent Constructors ---
cCollegeStudent::cCollegeStudent() : cStudent(), graduationExamScore(0.0f) {}

cCollegeStudent::cCollegeStudent(string id, string name, string addr, int credits, float score, float examScore)
    : cStudent(id, name, addr, credits, score), graduationExamScore(examScore) {}

// --- cUniversityStudent Constructors ---
cUniversityStudent::cUniversityStudent() : cStudent(), thesisName(""), thesisScore(0.0f) {}

cUniversityStudent::cUniversityStudent(string id, string name, string addr, int credits, float score, string thesis, float tScore)
    : cStudent(id, name, addr, credits, score), thesisName(thesis), thesisScore(tScore) {}