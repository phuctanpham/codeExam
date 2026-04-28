/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomial cPolynomial::operator+(const cPolynomial& other) const {
    int maxBac = (bac > other.bac) ? bac : other.bac;
    cPolynomial res(maxBac);
    
    for (int i = 0; i <= maxBac; ++i) {
        double heSo1 = (i <= bac) ? heSo[i] : 0.0;
        double heSo2 = (i <= other.bac) ? other.heSo[i] : 0.0;
        res.heSo[i] = heSo1 + heSo2;
    }
    
    // Luu y: Theo ly thuyet nen "chuan hoa" giam bac neu he so bac cao nhat = 0
    // nhung de giu hieu suat on dinh va chong memory leak thi cu giu dung maxBac
    return res;
}