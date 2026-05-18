/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Assignment 5
VAKALAND Real Estate Company needs to manage a list of real estate transactions. 
Currently, the company has 3 types of transactions:

Land Transactions: Transaction code, transaction date, unit price, land type ("A", "B", "C"), area.
If type B or C: total cost = area * unit price.
If type A: total cost = area * unit price * 1.5.

Townhouse Transactions: Transaction code, transaction date, unit price, house type ("premium", "regular"), address, area.
If premium house type: total cost = area * unit price.
If regular house type: total cost = area * unit price * 90%.

Apartment Transactions: Transaction code, transaction date, unit price, apartment code, floor position, area.
If the floor position is 1: total cost = area * unit price * 2.
If the floor position is 15 or above: total cost = area * unit price * 1.2.
For the remaining floor positions: total cost = area * unit price.

Applying inheritance and polymorphism, design classes and build a program to perform:
- Input a list of Land, Townhouse, Apartment transactions.
- Calculate the total quantity for each type.
- Calculate the average total cost of Apartment transactions.
- Identify the Townhouse transaction with the highest value (total cost).
- Output the list of transactions in December 2024.
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thiết kế Tinh gọn & Đa hình (Lean & Polymorphic Design):
1. Tính kế thừa (Reusable Agility): Lớp cơ sở `cTransaction` lưu trữ các thuộc tính 
   chung cốt lõi (Mã GD, Ngày GD, Đơn giá, Diện tích). Các lớp dẫn xuất (`cLandTransaction`, 
   `cTownhouseTransaction`, `cApartmentTransaction`) mở rộng thêm các thuộc tính 
   riêng biệt mà không cần viết lại mã cũ.
2. Đa hình (Polymorphism) & Ghi đè (Override): Phương thức `calculateCost()` được 
   khai báo là hàm ảo thuần túy (pure virtual) ở lớp cha. Điều này bắt buộc các 
   lớp con phải định nghĩa lại logic tính tiền cụ thể của chúng (tùy theo phân 
   loại A/B/C, premium/regular, hay số tầng).
3. Runtime Type Identification (RTTI): Lưu trữ mọi đối tượng vào một `vector<cTransaction*>`. 
   Sử dụng `dynamic_cast` trong hàm main để xác định và bóc tách từng loại đối 
   tượng (Đất, Nhà phố, Căn hộ) nhằm đếm số lượng, tìm giá trị lớn nhất (Nhà phố) 
   hoặc tính trung bình (Căn hộ) một cách chuẩn xác và an toàn.
================================================================================
*/

// ================================================================================
// PART 3: CODEBASE
// ================================================================================

// cTransaction.h
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef CTRANSACTION_H
#define CTRANSACTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class demonstrating Reusable Agility (Inheritance)
class cTransaction {
protected:
    string transactionCode;
    string transactionDate; // Format assumption: dd/mm/yyyy
    double unitPrice;
    double area;

public:
    // Constructors (Overloading functionality)
    cTransaction();
    cTransaction(string code, string date, double price, double area);
    
    // Virtual Destructor (Polymorphism necessity)
    virtual ~cTransaction() {}

    // Getters and Setters functionality
    string getTransactionCode() const { return transactionCode; }
    void setTransactionCode(const string& code) { transactionCode = code; }
    
    string getTransactionDate() const { return transactionDate; }
    void setTransactionDate(const string& date) { transactionDate = date; }
    
    double getUnitPrice() const { return unitPrice; }
    void setUnitPrice(double price) { unitPrice = price; }
    
    double getArea() const { return area; }
    void setArea(double a) { area = a; }

    // Virtual functions demonstrating Polymorphism and Override
    virtual void input();
    virtual void output() const;
    virtual double calculateCost() const = 0; // Pure virtual function

    // Operator overloading for I/O agility
    friend istream& operator>>(istream& is, cTransaction& t);
    friend ostream& operator<<(ostream& os, const cTransaction& t);
};

// Derived class: Land Transaction
class cLandTransaction : public cTransaction {
private:
    string landType; // "A", "B", "C"

public:
    cLandTransaction();
    cLandTransaction(string code, string date, double price, double area, string type);
    
    string getLandType() const { return landType; }
    void setLandType(const string& type) { landType = type; }

    void input() override;
    void output() const override;
    double calculateCost() const override;
};

// Derived class: Townhouse Transaction
class cTownhouseTransaction : public cTransaction {
private:
    string houseType; // "premium", "regular"
    string address;

public:
    cTownhouseTransaction();
    cTownhouseTransaction(string code, string date, double price, double area, string hType, string addr);
    
    string getHouseType() const { return houseType; }
    void setHouseType(const string& hType) { houseType = hType; }
    
    string getAddress() const { return address; }
    void setAddress(const string& addr) { address = addr; }

    void input() override;
    void output() const override;
    double calculateCost() const override;
};

// Derived class: Apartment Transaction
class cApartmentTransaction : public cTransaction {
private:
    string apartmentCode;
    int floorPosition;

public:
    cApartmentTransaction();
    cApartmentTransaction(string code, string date, double price, double area, string aCode, int floor);
    
    string getApartmentCode() const { return apartmentCode; }
    void setApartmentCode(const string& aCode) { apartmentCode = aCode; }
    
    int getFloorPosition() const { return floorPosition; }
    void setFloorPosition(int floor) { floorPosition = floor; }

    void input() override;
    void output() const override;
    double calculateCost() const override;
};

#endif // CTRANSACTION_H