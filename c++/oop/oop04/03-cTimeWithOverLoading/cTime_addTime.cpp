/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTimes.h"

// [THEM MOI] Cong them mot khoang thoi gian (CTime dong vai tro thoi luong)
// Vi du: 10:30:00 + 01:15:30 = 11:45:30
// Khac voi operator+(int s) chi cong theo giay, ham nay cong ca gio, phut, giay cung luc
CTime CTime::operator+(const CTime& duration) const {
    return CTime(gio  + duration.gio,
                 phut + duration.phut,
                 giay + duration.giay); // chuanHoa() tu dong xu ly tran
}

// [THEM MOI] Tru di mot khoang thoi gian (CTime dong vai tro thoi luong)
// Vi du: 10:30:00 - 01:15:30 = 09:14:30
// Khac voi operator-(int s) chi tru theo giay, ham nay tru ca gio, phut, giay cung luc
CTime CTime::operator-(const CTime& duration) const {
    return CTime(gio  - duration.gio,
                 phut - duration.phut,
                 giay - duration.giay); // chuanHoa() tu dong xu ly am va quay vong 24h
}
