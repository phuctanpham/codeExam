/* ================================================================================
PART 1: ASSIGNMENT DESCRIPTION
================================================================================
Assignment 4
Company X needs to manage a list of transactions. Currently, the company has 2 
types of transactions:

Gold transactions: Transaction code, transaction date, unit price, quantity, gold type.
Total cost is calculated as follows: Total cost = quantity * unit price.

Currency transactions: Transaction code, transaction date, unit price, quantity, 
exchange rate, currency type (there are 3 types: Vietnam dong, USD, Euro).
Total cost is calculated as follows:
If the currency is USD or Euro: total cost = quantity * unit price * exchange rate.
If the currency is VN: total cost = quantity * unit price.

Applying inheritance, design classes and build a program to perform the following:
- Input a list of gold transactions.
- Input a list of foreign currency transactions.
- Identify which gold transaction has the highest total cost.
- Identify which Euro foreign currency transaction has the lowest value (total cost).
- Output the transactions with a total cost of over 1 billion VND (1,000,000,000 VND).
================================================================================
*/

/* ================================================================================
PART 2: ALGORITHM EXPLANATION (GIẢI THÍCH THUẬT TOÁN)
================================================================================
Thiết kế Tinh gọn & Đa hình (Lean & Polymorphic Design):
1. Tính kế thừa (Reusable Agility): Lớp `cTransaction` đóng vai trò là xương sống 
   chứa các thuộc tính cốt lõi (mã, ngày, đơn giá, số lượng). `cGoldTransaction` 
   và `cCurrencyTransaction` kế thừa xương sống này để mở rộng các đặc tính riêng 
   (loại vàng, tỷ giá, loại tiền tệ) mà không phải viết lại mã nguồn cũ.
2. Đa hình (Polymorphism) & Ghi đè (Override): Phương thức `calculateCost()` được 
   thiết kế là hàm ảo thuần túy (pure virtual) trong lớp cha. Các lớp con bắt buộc 
   phải tự định nghĩa lại logic tính tiền của chính mình.
3. Kỹ thuật ép kiểu động (RTTI): Tại hàm `main`, mọi giao dịch được quản lý chung 
   bằng con trỏ `cTransaction*`. Để tìm Giao dịch Vàng lớn nhất hay Giao dịch 
   Euro nhỏ nhất, ta dùng `dynamic_cast` để xác định chính xác kiểu dữ liệu thực 
   tế đang trỏ tới tại thời điểm chạy (runtime).
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
    string transactionDate;
    double unitPrice;
    int quantity;

public:
    // Constructors (Overloading functionality)
    cTransaction();
    cTransaction(string code, string date, double price, int qty);
    
    // Virtual Destructor (Polymorphism necessity for safe memory management)
    virtual ~cTransaction() {}

    // Getters and Setters functionality
    string getTransactionCode() const { return transactionCode; }
    void setTransactionCode(const string& code) { transactionCode = code; }
    
    string getTransactionDate() const { return transactionDate; }
    void setTransactionDate(const string& date) { transactionDate = date; }
    
    double getUnitPrice() const { return unitPrice; }
    void setUnitPrice(double price) { unitPrice = price; }
    
    int getQuantity() const { return quantity; }
    void setQuantity(int qty) { quantity = qty; }

    // Virtual functions demonstrating Polymorphism and Override
    virtual void input();
    virtual void output() const;
    virtual double calculateCost() const = 0; // Pure virtual function

    // Operator overloading for I/O agility
    friend istream& operator>>(istream& is, cTransaction& t);
    friend ostream& operator<<(ostream& os, const cTransaction& t);
};

// Derived class: Gold Transaction
class cGoldTransaction : public cTransaction {
private:
    string goldType;

public:
    cGoldTransaction();
    cGoldTransaction(string code, string date, double price, int qty, string type);
    
    string getGoldType() const { return goldType; }
    void setGoldType(const string& type) { goldType = type; }

    void input() override;
    void output() const override;
    double calculateCost() const override;
};

// Derived class: Currency Transaction
class cCurrencyTransaction : public cTransaction {
private:
    double exchangeRate;
    string currencyType; // "VN", "USD", "Euro"

public:
    cCurrencyTransaction();
    cCurrencyTransaction(string code, string date, double price, int qty, double rate, string currType);
    
    double getExchangeRate() const { return exchangeRate; }
    void setExchangeRate(double rate) { exchangeRate = rate; }
    
    string getCurrencyType() const { return currencyType; }
    void setCurrencyType(const string& currType) { currencyType = currType; }

    void input() override;
    void output() const override;
    double calculateCost() const override;
};

#endif // CTRANSACTION_H