/* 
name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cComplex.h"

#include <cctype>
#include <sstream>
#include <string>

namespace {
// Chuyen chuoi thanh so thuc va kiem tra ky tu du.
bool parseDouble(const std::string& text, double& value) {
    std::stringstream stream(text);
    char extra = '\0';
    // Chi chap nhan mot so thuc day du, khong co ky tu thua.
    return (stream >> value) && !(stream >> extra);
}

// Doc va kiem tra so phuc theo dang a+bi hoac a-bi.
bool readComplexValue(const char* prompt, double& real, double& imaginary) {
    std::string line;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin >> std::ws, line)) {
            return false;
        }

        std::string compact;
        for (char ch : line) {
            if (!std::isspace(static_cast<unsigned char>(ch))) {
                compact.push_back(ch);
            }
        }

        // So phuc bat buoc ket thuc bang i, vi du 3+4i.
        if (compact.empty() || compact.back() != 'i') {
            std::cout << "Sai định dạng, hãy nhập a+bi hoặc a-bi.\n";
            continue;
        }

        std::string withoutI = compact.substr(0, compact.size() - 1);
        std::size_t splitPos = std::string::npos;
        for (std::size_t i = 1; i < withoutI.size(); ++i) {
            if (withoutI[i] == '+' || withoutI[i] == '-') {
                splitPos = i;
            }
        }

        if (splitPos == std::string::npos) {
            std::cout << "Sai định dạng, hãy nhập a+bi hoặc a-bi.\n";
            continue;
        }

        std::string realPart = withoutI.substr(0, splitPos);
        std::string imagPart = withoutI.substr(splitPos);

        // Kiem tra phan thuc.
        if (!parseDouble(realPart, real)) {
            std::cout << "Phần thực không hợp lệ, vui lòng nhập lại.\n";
            continue;
        }

        // Kiem tra phan ao, chap nhan +i hoac -i.
        if (imagPart == "+") {
            imaginary = 1.0;
        } else if (imagPart == "-") {
            imaginary = -1.0;
        } else if (!parseDouble(imagPart, imaginary)) {
            std::cout << "Phần ảo không hợp lệ, vui lòng nhập lại.\n";
            continue;
        }

        return true;
    }
}
}

// Khoi tao so phuc mac dinh 0 + 0i.
cComplex::cComplex() : real(0.0), imaginary(0.0) {}

// Khoi tao so phuc tu phan thuc va phan ao.
cComplex::cComplex(double real, double imaginary) {
    setValue(real, imaginary);
}

// Ham sao chep so phuc.
cComplex::cComplex(const cComplex& other) : real(other.real), imaginary(other.imaginary) {}

// Gan gia tri moi cho so phuc.
void cComplex::setValue(double newReal, double newImaginary) {
    real = newReal;
    imaginary = newImaginary;
}

// Nhap so phuc.
void cComplex::input() {
    readComplexValue("Nhập số phức (a+bi): ", real, imaginary);
}

// In so phuc ra man hinh.
void cComplex::output() const {
    std::cout << real;
    if (imaginary < 0) {
        std::cout << " - " << -imaginary << "i";
    } else {
        std::cout << " + " << imaginary << "i";
    }
}

// Cong hai so phuc.
cComplex cComplex::add(const cComplex& other) const {
    return cComplex(real + other.real, imaginary + other.imaginary);
}

// Tru hai so phuc.
cComplex cComplex::subtract(const cComplex& other) const {
    return cComplex(real - other.real, imaginary - other.imaginary);
}

// Nhan hai so phuc.
cComplex cComplex::multiply(const cComplex& other) const {
    return cComplex(
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}

// Chia hai so phuc.
cComplex cComplex::divide(const cComplex& other) const {
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    return cComplex(
        (real * other.real + imaginary * other.imaginary) / denominator,
        (imaginary * other.real - real * other.imaginary) / denominator
    );
}

// Kiem tra so phuc co bang 0 + 0i hay khong.
bool cComplex::isZero() const {
    return real == 0.0 && imaginary == 0.0;
}
