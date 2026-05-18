// cTransactions_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"

// --- cTransaction Constructors ---
cTransaction::cTransaction() : transactionCode(""), transactionDate(""), unitPrice(0.0), quantity(0) {}

cTransaction::cTransaction(string code, string date, double price, int qty)
    : transactionCode(code), transactionDate(date), unitPrice(price), quantity(qty) {}

// --- cGoldTransaction Constructors ---
cGoldTransaction::cGoldTransaction() : cTransaction(), goldType("") {}

cGoldTransaction::cGoldTransaction(string code, string date, double price, int qty, string type)
    : cTransaction(code, date, price, qty), goldType(type) {}

// --- cCurrencyTransaction Constructors ---
cCurrencyTransaction::cCurrencyTransaction() : cTransaction(), exchangeRate(1.0), currencyType("VN") {}

cCurrencyTransaction::cCurrencyTransaction(string code, string date, double price, int qty, double rate, string currType)
    : cTransaction(code, date, price, qty), exchangeRate(rate), currencyType(currType) {}