// cTransaction_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"
#include <limits>    // FIX: added — required for numeric_limits
#include <algorithm> // FIX: added — required for transform and tolower

int main() {
    vector<cTransaction*> transactions;
    int numGold, numCurr;

    // 1. Input lists
    cout << "Enter number of Gold Transactions: ";
    cin >> numGold;
    for (int i = 0; i < numGold; ++i) {
        cTransaction* gold = new cGoldTransaction();
        cin >> *gold; // Polymorphic operator overloading
        transactions.push_back(gold);
    }

    cout << "\nEnter number of Currency Transactions: ";
    cin >> numCurr;
    for (int i = 0; i < numCurr; ++i) {
        cTransaction* curr = new cCurrencyTransaction();
        cin >> *curr;
        transactions.push_back(curr);
    }

    // Process requirements
    cGoldTransaction* maxGoldTrans = nullptr;
    double maxGoldCost = -1.0;

    cCurrencyTransaction* minEuroTrans = nullptr;
    // FIX: use numeric_limits instead of magic number 1.79769e+308
    double minEuroCost = numeric_limits<double>::max();

    cout << "\n=== TRANSACTIONS > 1 BILLION VND ===\n";
    bool foundBillion = false;

    for (const auto& t : transactions) {
        double currentCost = t->calculateCost();

        // Target: Output transactions over 1,000,000,000 VND
        if (currentCost > 1000000000.0) {
            cout << *t;
            foundBillion = true;
        }

        // RTTI Target: Max Gold Transaction
        if (cGoldTransaction* gold = dynamic_cast<cGoldTransaction*>(t)) {
            if (currentCost > maxGoldCost) {
                maxGoldCost = currentCost;
                maxGoldTrans = gold;
            }
        }
        // RTTI Target: Min Euro Transaction
        else if (cCurrencyTransaction* curr = dynamic_cast<cCurrencyTransaction*>(t)) {
            // FIX: normalize to lowercase so "euro", "Euro", "EURO" all match
            string currType = curr->getCurrencyType();
            transform(currType.begin(), currType.end(), currType.begin(), ::tolower);
            if (currType == "euro" && currentCost < minEuroCost) {
                minEuroCost = currentCost;
                minEuroTrans = curr;
            }
        }
    }

    if (!foundBillion) {
        cout << "No transactions exceeded 1 billion VND.\n";
    }

    cout << "\n=== HIGHEST COST GOLD TRANSACTION ===\n";
    if (maxGoldTrans) {
        cout << *maxGoldTrans;
    } else {
        cout << "No gold transactions found.\n";
    }

    cout << "\n=== LOWEST COST EURO TRANSACTION ===\n";
    if (minEuroTrans) {
        cout << *minEuroTrans;
    } else {
        cout << "No Euro currency transactions found.\n";
    }

    // Lean memory management
    for (auto& t : transactions) {
        delete t;
    }
    transactions.clear();

    return 0;
}
