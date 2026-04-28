/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cAccount.h"

// Tinh khoang cach ngay bang toan tu - da duoc overload cua cDate
int cAccount::getSoNgayGui() const {
    int days = ngayRut - ngayGui;
    return (days > 0) ? days : 0;
}

// Tinh tien lai theo cong thuc: (Tien * Lai/100) * (SoNgay / 365)
double cAccount::tinhTienLai() const {
    int days = getSoNgayGui();
    return soTienGui * (laiSuatNam / 100.0) * ((double)days / 365.0);
}