// cTrip_main.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"
#include <iomanip>

int main() {
    vector<cTrip*> trips;

    cout << "=== ENTERING 2 INNER-CITY TRIPS ===\n";
    for (int i = 0; i < 2; ++i) {
        cTrip* inner = new cInnerCityTrip();
        cin >> *inner;
        trips.push_back(inner);
    }

    cout << "\n=== ENTERING 2 INTER-CITY TRIPS ===\n";
    for (int i = 0; i < 2; ++i) {
        cTrip* inter = new cInterCityTrip();
        cin >> *inter;
        trips.push_back(inter);
    }

    cout << "\n=== ALL TRIPS INFORMATION ===\n";
    double totalRevenue = 0;
    double innerRevenue = 0;
    double interRevenue = 0;

    for (const auto& t : trips) {
        cout << *t; 
        
        totalRevenue += t->getRevenue();
        
        if (dynamic_cast<cInnerCityTrip*>(t)) {
            innerRevenue += t->getRevenue();
        } else if (dynamic_cast<cInterCityTrip*>(t)) {
            interRevenue += t->getRevenue();
        }
    }

    cout << "\n=== REVENUE SUMMARY ===\n";
    cout << "Total Revenue (All Trips): " << fixed << setprecision(2) << totalRevenue << endl;
    cout << "Total Revenue (Inner-City): " << innerRevenue << endl;
    cout << "Total Revenue (Inter-City): " << interRevenue << endl;

    for (auto& t : trips) {
        delete t;
    }
    trips.clear();

    return 0;
}