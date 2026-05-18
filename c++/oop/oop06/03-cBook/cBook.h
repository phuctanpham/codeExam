/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Assignment 3
Library X needs to manage a list of book types. Information about book types includes:

Textbooks: Book code, import date, unit price, quantity, publisher, condition ("new", "old").
If the book condition is "new": total cost = quantity * unit price.
If the book condition is "old": total cost = quantity * unit price * 50%.
Reference books: Book code, import date, unit price, quantity, publisher, tax.
Total cost = quantity * unit price + tax.

Applying inheritance, implement classes to perform the following functions:
- Input information for Textbooks and Reference books.
- Output information for Textbooks and Reference books.
- Calculate the total cost for Textbooks and Reference books.

Write an illustrative program allowing the input of 3 books of each type, then:
- Calculate the total cost for each type.
- Calculate the average unit price of reference books.
- Output the textbooks from publisher K (allow user to input K).
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thiết kế Tinh gọn & Đa hình (Lean & Polymorphic Design):
1. Tính kế thừa (Reusable Agility): Lớp `cBook` chứa các thuộc tính chung (mã sách, 
   ngày nhập, đơn giá, số lượng, NXB). `cTextbook` và `cReferenceBook` kế thừa và 
   mở rộng thuộc tính riêng (tình trạng, thuế).
2. Đa hình (Polymorphism) & Ghi đè (Override): Phương thức `calculateTotalCost()` 
   là hàm ảo thuần túy (pure virtual) ở lớp cha, ép buộc các lớp con phải ghi đè 
   (override) quy tắc tính tiền cụ thể của chúng. I/O cũng được xử lý đa hình 
   thông qua các hàm ảo `input()` và `output()`.
3. Chồng toán tử (Operator Overloading): Gắn luồng `>>` và `<<` trực tiếp với đa 
   hình để việc nhập/xuất trở nên tự nhiên và gọn gàng.
4. Quản lý linh hoạt: Sử dụng `vector<cBook*>` làm danh sách chung. Dùng 
   `dynamic_cast` tại runtime (RTTI) để an toàn bóc tách dữ liệu khi cần tính 
   toán riêng (ví dụ: trung bình giá sách tham khảo, lọc sách giáo khoa theo NXB).
================================================================================
*/

// ================================================================================
// PART 3: CODEBASE
// ================================================================================

// cBook.h
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef CBOOK_H
#define CBOOK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class demonstrating Reusable Agility (Inheritance)
class cBook {
protected:
    string bookCode;
    string importDate;
    double unitPrice;
    int quantity;
    string publisher;

public:
    // Constructors (Overloading functionality)
    cBook();
    cBook(string code, string date, double price, int qty, string pub);

    // Virtual Destructor (Polymorphism necessity for safe memory management)
    virtual ~cBook() {}

    // Getters and Setters functionality
    string getBookCode() const { return bookCode; }
    void setBookCode(const string& code) { bookCode = code; }

    string getImportDate() const { return importDate; }
    void setImportDate(const string& date) { importDate = date; }

    double getUnitPrice() const { return unitPrice; }
    void setUnitPrice(double price) { unitPrice = price; }

    int getQuantity() const { return quantity; }
    void setQuantity(int qty) { quantity = qty; }

    string getPublisher() const { return publisher; }
    void setPublisher(const string& pub) { publisher = pub; }

    // Virtual functions demonstrating Polymorphism and Override
    virtual void input();
    virtual void output() const;
    virtual double calculateTotalCost() const = 0; // Pure virtual function

    // Operator overloading for I/O agility
    friend istream& operator>>(istream& is, cBook& b);
    friend ostream& operator<<(ostream& os, const cBook& b);
};

// Derived class: Textbook
class cTextbook : public cBook {
private:
    string condition; // "new" or "old"

public:
    cTextbook();
    cTextbook(string code, string date, double price, int qty, string pub, string cond);

    string getCondition() const { return condition; }
    void setCondition(const string& cond) { condition = cond; }

    void input() override;
    void output() const override;
    double calculateTotalCost() const override;
};

// Derived class: Reference Book
class cReferenceBook : public cBook {
private:
    double tax;

public:
    cReferenceBook();
    cReferenceBook(string code, string date, double price, int qty, string pub, double taxRate);

    double getTax() const { return tax; }
    void setTax(double taxRate) { tax = taxRate; }

    void input() override;
    void output() const override;
    double calculateTotalCost() const override;
};

#endif // CBOOK_H
