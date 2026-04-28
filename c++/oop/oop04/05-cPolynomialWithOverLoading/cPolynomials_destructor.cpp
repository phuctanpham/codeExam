/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cPolynomials.h"

cPolynomials::~cPolynomials() {
    if (arr != nullptr) {
        delete[] arr; // Se tu dong goi Destructor cua tung cPolynomial ben trong
        arr = nullptr;
    }
}