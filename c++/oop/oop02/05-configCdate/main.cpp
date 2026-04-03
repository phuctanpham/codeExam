/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cDate.h"

using namespace std;

int main() {
    cDate date1;
    cDate date2;

    cout << "Nhập date1\n";
    date1.input();

    cout << "\nNhập date2\n";
    date2.input();

    cout << "\nCác ngày ban đầu:\n";
    cout << "date1 = ";
    date1.output();
    cout << " (" << date1.getDayOfWeek() << ")\n";
    cout << "date2 = ";
    date2.output();
    cout << " (" << date2.getDayOfWeek() << ")\n";

    cout << "\nGán date1 bằng setValue(29, 2, 2024): ";
    date1.setValue(29, 2, 2024);
    date1.output();
    cout << " (" << date1.getDayOfWeek() << ")\n";

    cout << "Gán date2 bằng setDay/setMonth/setYear: ";
    date2.setDay(31);
    date2.setMonth(12);
    date2.setYear(2025);
    date2.output();
    cout << " (" << date2.getDayOfWeek() << ")\n";

    cout << "\nLấy giá trị bằng getter:\n";
    cout << "date1 = " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << "\n";
    cout << "date2 = " << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << "\n";

    cout << "\nKiểm tra năm nhuận:\n";
    cout << "date1 là năm nhuận? " << (date1.isLeapYear() ? "Có" : "Không") << "\n";
    cout << "date2 là năm nhuận? " << (date2.isLeapYear() ? "Có" : "Không") << "\n";

    cout << "\nCác thao tác tăng/giảm:\n";
    cout << "date1 tăng 10 ngày: ";
    date1.increaseDay(10);
    date1.output();
    cout << " (" << date1.getDayOfWeek() << ")\n";

    cout << "date1 giảm 2 tháng: ";
    date1.decreaseMonth(2);
    date1.output();
    cout << " (" << date1.getDayOfWeek() << ")\n";

    cout << "date2 tăng 1 năm: ";
    date2.increaseYear(1);
    date2.output();
    cout << " (" << date2.getDayOfWeek() << ")\n";

    cout << "date2 giảm 40 ngày: ";
    date2.decreaseDay(40);
    date2.output();
    cout << " (" << date2.getDayOfWeek() << ")\n";

    cout << "\n";
    return 0;
}
