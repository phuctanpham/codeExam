/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/

#ifndef CFRACTIONS_H
#define CFRACTIONS_H

#include <iostream>
using namespace std;

// --- Lớp biểu diễn 1 phân số ---
class cFraction {
private:
    int tu, mau;
    void simplify();
public:
    // OVERLOADING Constructor: Thiết lập phân số mặc định hoặc chuyển 1 số nguyên thành phân số (mẫu = 1)
    cFraction(int t = 0, int m = 1);
    ~cFraction();

    // OVERLOADING Toán tử Nhập/Xuất
    friend istream& operator>>(istream& is, cFraction& f);
    friend ostream& operator<<(ostream& os, const cFraction& f);

    // OVERLOADING Toán tử Số học
    // [SỬA] Thêm 'const' vào cuối: các phép tính không thay đổi đối tượng gốc,
    //       khai báo const để có thể gọi trên đối tượng hằng (const cFraction)
    cFraction operator+(const cFraction& other) const;
    cFraction operator-(const cFraction& other) const;
    cFraction operator*(const cFraction& other) const;
    cFraction operator/(const cFraction& other) const;

    // OVERLOADING Toán tử So sánh
    // [SỬA] Thêm 'const' vào cuối: so sánh không thay đổi dữ liệu,
    //       khai báo const là chuẩn C++ và tránh lỗi khi dùng với đối tượng hằng
    bool operator==(const cFraction& other) const;
    bool operator>(const cFraction& other) const;
    bool operator<(const cFraction& other) const;
};

// --- Lớp biểu diễn 1 dãy phân số ---
class cFractions {
private:
    int n;
    cFraction* arr;
public:
    cFractions(int size = 0);
    ~cFractions();

    // OVERLOADING Toán tử Nhập/Xuất cho cả dãy
    friend istream& operator>>(istream& is, cFractions& fs);
    friend ostream& operator<<(ostream& os, const cFractions& fs);

    // [SỬA] Thêm 'const' vào cuối: sum, max, min chỉ đọc dữ liệu, không sửa mảng
    cFraction sum() const;
    cFraction max() const;
    cFraction min() const;
    void sortAscending(); // Không const vì sắp xếp thay đổi thứ tự mảng
};

#endif
