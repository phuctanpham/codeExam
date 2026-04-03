/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_DATE_H
#define C_DATE_H

#include <iostream>
#include <string>

class cDate {
private:
    int day;
    int month;
    int year;

    static bool isLeapYearInternal(int year);
    static int daysInMonthInternal(int month, int year);
    static long long daysFromCivil(int year, int month, int day);
    static void civilFromDays(long long days, int& year, int& month, int& day);
    void normalize();
    void shiftDays(int deltaDays);

public:
    cDate();
    cDate(int day, int month, int year);
    cDate(const cDate& other);

    void setValue(int newDay, int newMonth, int newYear);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void increaseDay(int value);
    void increaseMonth(int value);
    void increaseYear(int value);
    void decreaseDay(int value);
    void decreaseMonth(int value);
    void decreaseYear(int value);

    bool isLeapYear() const;
    std::string getDayOfWeek() const;

    void input();
    void output() const;
};

#endif
