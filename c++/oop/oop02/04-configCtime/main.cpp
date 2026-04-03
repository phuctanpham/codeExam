/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include <iostream>

#include "cTime.h"

int main() {
    cTime time1;
    cTime time2;

    std::cout << "Nhập time1\n";
    time1.input();

    std::cout << "\nNhập time2\n";
    time2.input();

    std::cout << "\nCác thời điểm ban đầu:\n";
    std::cout << "time1 = ";
    time1.output();
    std::cout << "\ntime2 = ";
    time2.output();

    std::cout << "\n\nGán time1 bằng setValue(25, 61, 90): ";
    time1.setValue(25, 61, 90);
    time1.output();

    std::cout << "\nGán time2 bằng setHours/setMinutes/setSeconds: ";
    time2.setHours(10);
    time2.setMinutes(20);
    time2.setSeconds(30);
    time2.output();

    std::cout << "\n\nLấy giá trị bằng getter:\n";
    std::cout << "time1 = " << time1.getHours() << "h " << time1.getMinutes() << "m " << time1.getSeconds() << "s\n";
    std::cout << "time2 = " << time2.getHours() << "h " << time2.getMinutes() << "m " << time2.getSeconds() << "s\n";

    std::cout << "\nCác thao tác tăng/giảm:\n";
    std::cout << "time1 tăng 2 giờ: ";
    time1.increaseHours(2);
    time1.output();

    std::cout << "\ntime1 tăng 125 giây: ";
    time1.increaseSeconds(125);
    time1.output();

    std::cout << "\ntime2 giảm 15 phút: ";
    time2.decreaseMinutes(15);
    time2.output();

    std::cout << "\ntime2 giảm 4000 giây: ";
    time2.decreaseSeconds(4000);
    time2.output();

    std::cout << "\n";
    return 0;
}
