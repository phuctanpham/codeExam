/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Assignment 1
Suppose the University of Information Technology HCMC trains students in 2 systems: 
the College system and the University system.

Information to manage for a college student includes: student ID, full name, 
address, total credits, average score, and graduation exam score.
Information to manage for a university student includes: student ID, full name, 
address, total credits, average score, thesis name, and thesis score.

The graduation criteria for students in each system are different:
- College students graduate when they have total credits of 110 or more, an 
  average score of 5 or more, and a graduation exam score of 5 or more.
- University students graduate when they have total credits of 145 or more, an 
  average score of 5 or more, and successfully defend a thesis with a score of 5 or more.

Applying inheritance and polymorphism, design classes and build a program to perform:
- Input a list of university students and a list of college students.
- Output the list of students.
- Output the list of students eligible for graduation.
- Output the list of students not eligible for graduation.
- Identify which university student has the highest average score.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thiết kế Tinh gọn & Đa hình (Lean & Polymorphic Design):
1. Tính kế thừa (Reusable Agility): Lớp cơ sở `cStudent` đóng gói các thuộc tính 
   dùng chung (MSSV, Họ tên, Địa chỉ, Số tín chỉ, Điểm TB). `cCollegeStudent` và 
   `cUniversityStudent` kế thừa `cStudent` để mở rộng thêm tiêu chí tốt nghiệp riêng.
2. Đa hình (Polymorphism) & Ghi đè (Override): Các hàm `input()`, `output()`, và 
   đặc biệt là `isEligibleForGraduation()` được định nghĩa là hàm ảo (virtual). 
   Mỗi lớp con sẽ cung cấp logic xét tốt nghiệp riêng. Hệ thống tự động gọi hàm 
   chuẩn xác tại thời điểm chạy (runtime) dựa trên loại sinh viên.
3. Phân tách Module: Tách bạch hoàn toàn khai báo (.h) và triển khai (.cpp). Các 
   Getters/Setters được đưa ra khỏi file header nhằm đảm bảo mã nguồn gọn gàng.
4. Chồng toán tử (Operator Overloading): Định nghĩa lại `>>` và `<<` thông qua 
   con trỏ lớp cha, tích hợp ngầm định Đa hình để I/O mượt mà.
5. Kỹ thuật RTTI: Dùng `dynamic_cast` trong hàm main để bóc tách an toàn các sinh 
   viên Đại học (University) khi cần tìm người có điểm trung bình cao nhất.
================================================================================
*/

// ================================================================================
// PART 3: CODEBASE
// ================================================================================

// cStudent.h
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class demonstrating Reusable Agility (Inheritance)
class cStudent {
protected:
    string studentID;
    string fullName;
    string address;
    int totalCredits;
    float averageScore;

public:
    // Constructors functionality (Overloading)
    cStudent();
    cStudent(string id, string name, string addr, int credits, float score);
    
    // Virtual Destructor (Polymorphism necessity)
    virtual ~cStudent() {}

    // Getters and Setters - Declarations ONLY
    string getStudentID() const;
    void setStudentID(const string& id);
    
    string getFullName() const;
    void setFullName(const string& name);
    
    string getAddress() const;
    void setAddress(const string& addr);
    
    int getTotalCredits() const;
    void setTotalCredits(int credits);
    
    float getAverageScore() const;
    void setAverageScore(float score);

    // Virtual functions demonstrating Polymorphism and Override
    virtual void input();
    virtual void output() const;
    virtual bool isEligibleForGraduation() const = 0; // Pure virtual function

    // Operator overloading functionality
    friend istream& operator>>(istream& is, cStudent& st);
    friend ostream& operator<<(ostream& os, const cStudent& st);
};

// Derived class: College Student
class cCollegeStudent : public cStudent {
private:
    float graduationExamScore;

public:
    cCollegeStudent();
    cCollegeStudent(string id, string name, string addr, int credits, float score, float examScore);
    
    // Getters and Setters
    float getGraduationExamScore() const;
    void setGraduationExamScore(float score);

    void input() override;
    void output() const override;
    bool isEligibleForGraduation() const override;
};

// Derived class: University Student
class cUniversityStudent : public cStudent {
private:
    string thesisName;
    float thesisScore;

public:
    cUniversityStudent();
    cUniversityStudent(string id, string name, string addr, int credits, float score, string thesis, float tScore);
    
    // Getters and Setters
    string getThesisName() const;
    void setThesisName(const string& thesis);
    
    float getThesisScore() const;
    void setThesisScore(float score);

    void input() override;
    void output() const override;
    bool isEligibleForGraduation() const override;
};

#endif // CSTUDENT_H