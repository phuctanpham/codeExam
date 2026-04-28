/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cAccount.h"

ostream& operator<<(ostream& os, const cAccount& acc) {
    os << "------------------------------------------\n";
    os << "So tien gui goc: " << fixed << setprecision(2) << acc.soTienGui << " VND\n";
    os << "Lai suat       : " << acc.laiSuatNam << " %/nam\n";
    os << "Thoi gian gui  : Tu " << acc.ngayGui << " (" << acc.ngayGui.getWeekday() << ")\n";
    os << "                 Den " << acc.ngayRut << " (" << acc.ngayRut.getWeekday() << ")\n";
    os << "So ngay thuc te: " << acc.getSoNgayGui() << " ngay\n";
    os << "Tien lai       : " << fixed << setprecision(2) << acc.tinhTienLai() << " VND\n";
    os << "TONG THU VE    : " << fixed << setprecision(2) << (acc.soTienGui + acc.tinhTienLai()) << " VND\n";
    os << "------------------------------------------\n";
    return os;
}