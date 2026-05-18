// cTransaction_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTransaction.h"
#include <iomanip>  // FIX: added — required for fixed and setprecision

int main() {
    vector<cTransaction*> transactions;
    int numLand, numTownhouse, numApt;

    // 1. Input lists
    cout << "Enter number of Land Transactions: ";
    cin >> numLand;
    for (int i = 0; i < numLand; ++i) {
        cTransaction* land = new cLandTransaction();
        cin >> *land;
        transactions.push_back(land);
    }

    cout << "\nEnter number of Townhouse Transactions: ";
    cin >> numTownhouse;
    for (int i = 0; i < numTownhouse; ++i) {
        cTransaction* th = new cTownhouseTransaction();
        cin >> *th;
        transactions.push_back(th);
    }

    cout << "\nEnter number of Apartment Transactions: ";
    cin >> numApt;
    for (int i = 0; i < numApt; ++i) {
        cTransaction* apt = new cApartmentTransaction();
        cin >> *apt;
        transactions.push_back(apt);
    }

    // 2. Process Requirements
    int countLand = 0, countTownhouse = 0, countApt = 0;
    double sumAptCost = 0.0;

    cTownhouseTransaction* maxTownhouse = nullptr;
    double maxTownhouseCost = -1.0;

    cout << "\n=== TRANSACTIONS IN DECEMBER 2024 ===\n";
    bool foundDec2024 = false;

    for (const auto& t : transactions) {
        // Checking for December 2024 (format: dd/12/2024)
        if (t->getTransactionDate().find("/12/2024") != string::npos) {
            cout << *t;
            foundDec2024 = true;
        }

        // RTTI Logic for Classification and Calculations
        if (cLandTransaction* land = dynamic_cast<cLandTransaction*>(t)) {
            countLand++;
        }
        else if (cTownhouseTransaction* th = dynamic_cast<cTownhouseTransaction*>(t)) {
            countTownhouse++;
            double cost = th->calculateCost();
            if (cost > maxTownhouseCost) {
                maxTownhouseCost = cost;
                maxTownhouse = th;
            }
        }
        else if (cApartmentTransaction* apt = dynamic_cast<cApartmentTransaction*>(t)) {
            countApt++;
            sumAptCost += apt->calculateCost();
        }
    }

    if (!foundDec2024) cout << "No transactions found in December 2024.\n";

    // 3. Display Results
    cout << "\n=== TRANSACTION QUANTITIES ===\n";
    cout << "Total Land Transactions: " << countLand << endl;
    cout << "Total Townhouse Transactions: " << countTownhouse << endl;
    cout << "Total Apartment Transactions: " << countApt << endl;

    cout << "\n=== AVERAGE APARTMENT COST ===\n";
    if (countApt > 0) {
        cout << fixed << setprecision(2) << (sumAptCost / countApt) << endl;
    } else {
        cout << "No apartment transactions available to calculate average.\n";
    }

    cout << "\n=== HIGHEST COST TOWNHOUSE TRANSACTION ===\n";
    if (maxTownhouse) {
        cout << *maxTownhouse;
    } else {
        cout << "No townhouse transactions found.\n";
    }

    // Memory Cleanup (Lean Philosophy)
    for (auto& t : transactions) {
        delete t;
    }
    transactions.clear();

    return 0;
}
