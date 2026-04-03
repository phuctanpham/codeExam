/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTime.h"

#include <iomanip>
#include <sstream>
#include <string>

namespace {
constexpr int kSecondsPerMinute = 60;
constexpr int kMinutesPerHour = 60;
constexpr int kSecondsPerHour = kSecondsPerMinute * kMinutesPerHour;
constexpr int kSecondsPerDay = 24 * kSecondsPerHour;

// Doc va kiem tra thoi gian theo dang HH:MM:SS.
bool readTimeParts(const char* prompt, int& hours, int& minutes, int& seconds) {
    std::string line;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin >> std::ws, line)) {
            return false;
        }

        std::stringstream stream(line);
        char firstSeparator = '\0';
        char secondSeparator = '\0';
        char extra = '\0';

        // Kiem tra dung dang HH:MM:SS va gio-phut-giay nam trong mien hop le.
        if (stream >> hours >> firstSeparator >> minutes >> secondSeparator >> seconds &&
            !(stream >> extra) &&
            firstSeparator == ':' &&
            secondSeparator == ':' &&
            hours >= 0 && hours <= 23 &&
            minutes >= 0 && minutes <= 59 &&
            seconds >= 0 && seconds <= 59) {
            return true;
        }

        std::cout << "Sai thời gian, hãy nhập HH:MM:SS (00-23:00-59:00-59).\n";
    }
}
}

// Khoi tao thoi gian mac dinh 00:00:00.
cTime::cTime() : hours(0), minutes(0), seconds(0) {}

// Khoi tao thoi gian tu gio, phut, giay.
cTime::cTime(int hours, int minutes, int seconds) {
    setValue(hours, minutes, seconds);
}

// Ham sao chep thoi gian.
cTime::cTime(const cTime& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

// Quy doi gio-phut-giay ve tong so giay.
int cTime::toSeconds(int h, int m, int s) {
    return h * kSecondsPerHour + m * kSecondsPerMinute + s;
}

// Chuan hoa thoi gian ve khoang 00:00:00 den 23:59:59.
void cTime::normalize() {
    int totalSeconds = toSeconds(hours, minutes, seconds) % kSecondsPerDay;
    if (totalSeconds < 0) {
        totalSeconds += kSecondsPerDay;
    }

    hours = totalSeconds / kSecondsPerHour;
    totalSeconds %= kSecondsPerHour;
    minutes = totalSeconds / kSecondsPerMinute;
    seconds = totalSeconds % kSecondsPerMinute;
}

// Gan gia tri moi cho thoi gian.
void cTime::setValue(int newHours, int newMinutes, int newSeconds) {
    hours = newHours;
    minutes = newMinutes;
    seconds = newSeconds;
    normalize();
}

// Gan gio moi.
void cTime::setHours(int newHours) {
    hours = newHours;
    normalize();
}

// Gan phut moi.
void cTime::setMinutes(int newMinutes) {
    minutes = newMinutes;
    normalize();
}

// Gan giay moi.
void cTime::setSeconds(int newSeconds) {
    seconds = newSeconds;
    normalize();
}

// Lay gio hien tai.
int cTime::getHours() const {
    return hours;
}

// Lay phut hien tai.
int cTime::getMinutes() const {
    return minutes;
}

// Lay giay hien tai.
int cTime::getSeconds() const {
    return seconds;
}

// Tang gio theo so luong cho truoc.
void cTime::increaseHours(int value) {
    hours += value;
    normalize();
}

// Tang phut theo so luong cho truoc.
void cTime::increaseMinutes(int value) {
    minutes += value;
    normalize();
}

// Tang giay theo so luong cho truoc.
void cTime::increaseSeconds(int value) {
    seconds += value;
    normalize();
}

// Giam gio theo so luong cho truoc.
void cTime::decreaseHours(int value) {
    hours -= value;
    normalize();
}

// Giam phut theo so luong cho truoc.
void cTime::decreaseMinutes(int value) {
    minutes -= value;
    normalize();
}

// Giam giay theo so luong cho truoc.
void cTime::decreaseSeconds(int value) {
    seconds -= value;
    normalize();
}

// Nhap thoi gian.
void cTime::input() {
    readTimeParts("Nhập thời gian (HH:MM:SS): ", hours, minutes, seconds);
}

// In thoi gian theo dang HH:MM:SS.
void cTime::output() const {
    std::cout << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds;
}
