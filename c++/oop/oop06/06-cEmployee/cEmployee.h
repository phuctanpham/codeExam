/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Assignment 6
Suppose the Company has two types of employees: Office employees and Production employees.
Write a program to manage and calculate the salary for each employee of the company:

Each employee needs to manage the following information: Full name, date of birth, salary.
The company needs to calculate the salary for employees as follows:
- For production employees: Salary = base salary + number of products * 5,000
- For office employees: Salary = number of working days * 100,000

Applying inheritance and polymorphism, design classes and build a program to perform:
- Input a list of production employees and a list of office employees.
- Calculate the salary for each employee.
- Output the information of the list of employees.
- Calculate the total salary that the company has to pay its employees.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thiết kế Tinh gọn & Đa hình (Lean & Polymorphic Design):
1. Tính kế thừa (Reusable Agility): Lớp cơ sở `cEmployee` lưu trữ các thông tin 
   chung (Họ tên, Ngày sinh, Lương). Các lớp dẫn xuất `cProductionEmployee` và 
   `cOfficeEmployee` tái sử dụng lại các thuộc tính này và mở rộng thêm các yếu 
   tố đặc thù (Lương cơ bản, Số sản phẩm, Số ngày công).
2. Đa hình (Polymorphism) & Ghi đè (Override): Phương thức `calculateSalary()` 
   được thiết kế là hàm ảo thuần túy (pure virtual) trong lớp cha. Các lớp con 
   buộc phải tự định nghĩa lại (override) công thức tính lương của riêng mình.
3. Cập nhật trạng thái (State Update): Khi gọi `calculateSalary()`, kết quả tính 
   toán sẽ tự động được gán ngược lại vào thuộc tính `salary` của lớp cha thông 
   qua Setters để quản lý thống nhất.
4. Chồng toán tử (Operator Overloading): Định nghĩa lại `>>` và `<<` kết hợp 
   với các hàm ảo `input()` và `output()` để việc nhập/xuất danh sách nhân viên 
   diễn ra tự nhiên, loại bỏ hoàn toàn các cấu trúc if-else kiểm tra kiểu dữ liệu.
================================================================================
*/

// ================================================================================
// PART 3: CODEBASE
// ================================================================================

// cEmployee.h
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class demonstrating Reusable Agility (Inheritance)
class cEmployee {
protected:
    string fullName;
    string dob;
    double salary;

public:
    // Constructors (Overloading functionality)
    cEmployee();
    cEmployee(string name, string dateOfBirth, double sal);
    
    // Virtual Destructor (Polymorphism necessity for safe memory management)
    virtual ~cEmployee() {}

    // Getters and Setters functionality
    string getFullName() const { return fullName; }
    void setFullName(const string& name) { fullName = name; }
    
    string getDob() const { return dob; }
    void setDob(const string& dateOfBirth) { dob = dateOfBirth; }
    
    double getSalary() const { return salary; }
    void setSalary(double sal) { salary = sal; }

    // Virtual functions demonstrating Polymorphism and Override
    virtual void input();
    virtual void output() const;
    virtual double calculateSalary() const = 0; // FIX: const // Pure virtual function

    // Operator overloading for I/O agility
    friend istream& operator>>(istream& is, cEmployee& emp);
    friend ostream& operator<<(ostream& os, const cEmployee& emp);
};

// Derived class: Production Employee
class cProductionEmployee : public cEmployee {
private:
    double baseSalary;
    int numProducts;

public:
    cProductionEmployee();
    cProductionEmployee(string name, string dateOfBirth, double sal, double bSalary, int prods);
    
    double getBaseSalary() const { return baseSalary; }
    void setBaseSalary(double bSalary) { baseSalary = bSalary; }
    
    int getNumProducts() const { return numProducts; }
    void setNumProducts(int prods) { numProducts = prods; }

    void input() override;
    void output() const override;
    double calculateSalary() const override; // FIX: const
};

// Derived class: Office Employee
class cOfficeEmployee : public cEmployee {
private:
    int workingDays;

public:
    cOfficeEmployee();
    cOfficeEmployee(string name, string dateOfBirth, double sal, int days);
    
    int getWorkingDays() const { return workingDays; }
    void setWorkingDays(int days) { workingDays = days; }

    void input() override;
    void output() const override;
    double calculateSalary() const override; // FIX: const
};

#endif // CEMPLOYEE_H