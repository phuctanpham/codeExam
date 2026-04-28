/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cAccount.h"

cAccount::cAccount(double tien, double lai) {
    soTienGui = (tien > 0) ? tien : 0;
    laiSuatNam = (lai > 0) ? lai : 0;
}