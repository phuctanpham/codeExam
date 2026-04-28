/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

// In da thuc toi uu (khong in he so 0, in x thay vi x^1, dau cong/tru dep mat)
ostream& operator<<(ostream& os, const cPolynomial& p) {
    bool isAllZero = true;
    for (int i = p.bac; i >= 0; --i) {
        if (p.heSo[i] == 0) continue;
        
        // Xu ly dau '+' / '-'
        if (isAllZero) {
            if (p.heSo[i] < 0) os << "-";
        } else {
            if (p.heSo[i] > 0) os << " + ";
            else os << " - ";
        }
        
        double absVal = abs(p.heSo[i]);
        
        // Xu ly he so 1 (khong in so 1 neu co x di kem)
        if (absVal != 1 || i == 0) {
            os << absVal;
        }
        
        // Xu ly bien x
        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
        
        isAllZero = false;
    }
    
    // Neu tat ca he so la 0
    if (isAllZero) os << "0";
    
    return os;
}