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

// [SUA] Doi sang cong thuc tinh lai theo thang (30 ngay/thang) thay vi chia 365 thuan tuy.
//        Cong thuc ngan hang Viet Nam pho bien: Lai = Tien * LaiSuat/100 * SoNgay/360
//        (360 = 12 thang x 30 ngay, chuan ngan hang hay dung hon 365 thuan tuy lich)
double cAccount::tinhTienLai() const {
    int days = getSoNgayGui();
    return soTienGui * (laiSuatNam / 100.0) * ((double)days / 360.0);
}
