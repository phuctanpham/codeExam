/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef C_TIME_H
#define C_TIME_H

#include <iostream>

class cTime {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();
    static int toSeconds(int h, int m, int s);

public:
    cTime();
    cTime(int hours, int minutes, int seconds);
    cTime(const cTime& other);

    void setValue(int newHours, int newMinutes, int newSeconds);
    void setHours(int newHours);
    void setMinutes(int newMinutes);
    void setSeconds(int newSeconds);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void increaseHours(int value);
    void increaseMinutes(int value);
    void increaseSeconds(int value);
    void decreaseHours(int value);
    void decreaseMinutes(int value);
    void decreaseSeconds(int value);

    void input();
    void output() const;
};

#endif
