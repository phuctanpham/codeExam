/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cDate.h"

#include <array>
#include <sstream>
#include <string>

using namespace std;

namespace {
const array<string, 7> kDayNames = {
    "Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"
};

// Doc mot so nguyen tu chuoi va kiem tra ky tu du.
bool readInteger(const char* prompt, int& value) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char extra = '\0';
        // Chi chap nhan mot so nguyen hop le, khong co ky tu thua.
        if (stream >> value && !(stream >> extra)) {
            return true;
        }

        cout << "Số không hợp lệ, vui lòng nhập lại.\n";
    }
}

// Doc va kiem tra ngay theo dang dd/mm/yyyy hoac dd-mm-yyyy.
bool readDateParts(const char* prompt, int& day, int& month, int& year) {
    string line;

    while (true) {
        cout << prompt;
        if (!getline(cin >> ws, line)) {
            return false;
        }

        stringstream stream(line);
        char firstSeparator = '\0';
        char secondSeparator = '\0';
        char extra = '\0';

        // Kiem tra dung dinh dang dd/mm/yyyy hoac dd-mm-yyyy.
        if (stream >> day >> firstSeparator >> month >> secondSeparator >> year &&
            !(stream >> extra) &&
            firstSeparator == secondSeparator &&
            (firstSeparator == '/' || firstSeparator == '-')) {
            return true;
        }

        cout << "Sai định dạng ngày, hãy nhập dd/mm/yyyy hoặc dd-mm-yyyy.\n";
    }
}
}

// Khoi tao ngay mac dinh 01/01/2000.
cDate::cDate() : day(1), month(1), year(2000) {}

// Khoi tao ngay tu bo ba day/month/year.
cDate::cDate(int day, int month, int year) {
    setValue(day, month, year);
}

// Ham sao chep ngay thang nam.
cDate::cDate(const cDate& other) : day(other.day), month(other.month), year(other.year) {}

// Kiem tra mot nam co phai nam nhuan khong.
bool cDate::isLeapYearInternal(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Tra ve so ngay cua thang trong nam cho truoc.
int cDate::daysInMonthInternal(int month, int year) {
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        return isLeapYearInternal(year) ? 29 : 28;
    }
    if (month < 1 || month > 12) {
        return 31;
    }
    return daysInMonth[month - 1];
}

// Chuyen ngay lich sang so ngay serial.
long long cDate::daysFromCivil(int year, int month, int day) {
    year -= month <= 2;
    const long long era = (year >= 0 ? year : year - 399) / 400;
    const unsigned yoe = static_cast<unsigned>(year - era * 400);
    const unsigned doy = (153u * (month + (month > 2 ? -3 : 9)) + 2) / 5 + day - 1;
    const unsigned doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
    return era * 146097 + static_cast<long long>(doe) - 719468;
}

// Chuyen so ngay serial nguoc lai ngay/thang/nam.
void cDate::civilFromDays(long long days, int& year, int& month, int& day) {
    days += 719468;
    const long long era = (days >= 0 ? days : days - 146096) / 146097;
    const unsigned doe = static_cast<unsigned>(days - era * 146097);
    const unsigned yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
    year = static_cast<int>(yoe) + static_cast<int>(era * 400);
    const unsigned doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    const unsigned mp = (5 * doy + 2) / 153;
    day = static_cast<int>(doy - (153 * mp + 2) / 5 + 1);
    month = static_cast<int>(mp + (mp < 10 ? 3 : -9));
    year += (month <= 2);
}

// Chuan hoa ngay thang nam ve gia tri hop le theo lich.
void cDate::normalize() {
    long long serial = daysFromCivil(year, month, day);
    civilFromDays(serial, year, month, day);
}

// Dich ngay hien tai them/bot so ngay cho truoc.
void cDate::shiftDays(int deltaDays) {
    long long serial = daysFromCivil(year, month, day);
    serial += deltaDays;
    civilFromDays(serial, year, month, day);
}

// Gan ngay-thang-nam moi.
void cDate::setValue(int newDay, int newMonth, int newYear) {
    day = newDay;
    month = newMonth;
    year = newYear;
    normalize();
}

// Gan ngay moi.
void cDate::setDay(int newDay) {
    day = newDay;
    normalize();
}

// Gan thang moi.
void cDate::setMonth(int newMonth) {
    month = newMonth;
    normalize();
}

// Gan nam moi.
void cDate::setYear(int newYear) {
    year = newYear;
    normalize();
}

// Lay ngay hien tai.
int cDate::getDay() const {
    return day;
}

// Lay thang hien tai.
int cDate::getMonth() const {
    return month;
}

// Lay nam hien tai.
int cDate::getYear() const {
    return year;
}

// Tang so ngay.
void cDate::increaseDay(int value) {
    shiftDays(value);
}

// Tang so thang.
void cDate::increaseMonth(int value) {
    month += value;
    normalize();
}

// Tang so nam.
void cDate::increaseYear(int value) {
    year += value;
    normalize();
}

// Giam so ngay.
void cDate::decreaseDay(int value) {
    shiftDays(-value);
}

// Giam so thang.
void cDate::decreaseMonth(int value) {
    month -= value;
    normalize();
}

// Giam so nam.
void cDate::decreaseYear(int value) {
    year -= value;
    normalize();
}

// Kiem tra nam hien tai co phai nam nhuan.
bool cDate::isLeapYear() const {
    return isLeapYearInternal(year);
}

// Tra ve thu trong tuan cua ngay hien tai.
string cDate::getDayOfWeek() const {
    long long serial = daysFromCivil(year, month, day);
    int index = static_cast<int>((serial + 4) % 7);
    if (index < 0) {
        index += 7;
    }
    return kDayNames[index];
}

// Nhap ngay thang nam tu ban phim, co kiem tra hop le.
void cDate::input() {
    while (true) {
        if (!readDateParts("Nhập ngày (dd/mm/yyyy): ", day, month, year)) {
            return;
        }

        // Kiem tra ngay-thang-nam co ton tai trong lich hay khong.
        if (month >= 1 && month <= 12 && day >= 1 && day <= daysInMonthInternal(month, year)) {
            return;
        }

        cout << "Ngày không tồn tại trong lịch, vui lòng nhập lại.\n";
    }
}

// In ngay theo dang dd/mm/yyyy.
void cDate::output() const {
    cout << (day < 10 ? "0" : "") << day << "/"
         << (month < 10 ? "0" : "") << month << "/"
         << year;
}
