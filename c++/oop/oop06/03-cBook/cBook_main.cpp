// cBook_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cBook.h"
#include <iomanip>  // FIX: added — required for fixed and setprecision

int main() {
    vector<cBook*> library;

    // Requirement: Input 3 books of each type
    cout << "=== ENTERING 3 TEXTBOOKS ===\n";
    for (int i = 0; i < 3; ++i) {
        cBook* tb = new cTextbook();
        cin >> *tb; // Polymorphic operator overloading
        library.push_back(tb);
    }

    cout << "\n=== ENTERING 3 REFERENCE BOOKS ===\n";
    for (int i = 0; i < 3; ++i) {
        cBook* rb = new cReferenceBook();
        cin >> *rb;
        library.push_back(rb);
    }

    // Requirements Calculations
    double totalTextbookCost = 0.0;
    double totalRefBookCost = 0.0;
    double sumRefBookPrice = 0.0;
    int refBookCount = 0;

    cout << "\n=== LIBRARY INFORMATION ===\n";
    for (const auto& b : library) {
        cout << *b; // Display info polymorphically

        // RTTI to segregate operations based on derived type
        if (cTextbook* tb = dynamic_cast<cTextbook*>(b)) {
            totalTextbookCost += tb->calculateTotalCost();
        } else if (cReferenceBook* rb = dynamic_cast<cReferenceBook*>(b)) {
            totalRefBookCost += rb->calculateTotalCost();
            sumRefBookPrice += rb->getUnitPrice();
            refBookCount++;
        }
    }

    cout << "\n=== CALCULATIONS ===\n";
    cout << "Total Cost for Textbooks: " << fixed << setprecision(2) << totalTextbookCost << endl;
    cout << "Total Cost for Reference Books: " << totalRefBookCost << endl;

    if (refBookCount > 0) {
        cout << "Average Unit Price of Reference Books: " << (sumRefBookPrice / refBookCount) << endl;
    }

    cout << "\n=== FIND TEXTBOOKS BY PUBLISHER ===\n";
    string targetPub;
    cout << "Enter Publisher name (K) to search: ";
    cin.ignore();
    getline(cin, targetPub);

    bool found = false;
    for (const auto& b : library) {
        if (cTextbook* tb = dynamic_cast<cTextbook*>(b)) {
            if (tb->getPublisher() == targetPub) {
                cout << *tb;
                found = true;
            }
        }
    }
    if (!found) cout << "No textbooks found from publisher: " << targetPub << endl;

    // Lean memory management cleanup
    for (auto& b : library) {
        delete b;
    }
    library.clear();

    return 0;
}
