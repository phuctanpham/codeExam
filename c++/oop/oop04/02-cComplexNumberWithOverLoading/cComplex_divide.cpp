/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplexNumber.h"

cComplex cComplex::operator/(const cComplex& other) const {
    float mau_chung = other.thuc * other.thuc + other.ao * other.ao;
    
    // Kiem tra loi chia cho 0
    if (mau_chung == 0) {
        cout << "[Canh bao] Phep chia cho 0! Tra ve so phuc mac dinh (0 + 0i)." << endl;
        return cComplex(0, 0); 
    }
    
    float t = (thuc * other.thuc + ao * other.ao) / mau_chung;
    float a = (ao * other.thuc - thuc * other.ao) / mau_chung;
    return cComplex(t, a);
}