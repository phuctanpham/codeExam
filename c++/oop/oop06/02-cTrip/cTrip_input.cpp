// cTrip_input.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"

void cTrip::input() {
    cout << "Enter Trip Code: ";
    cin >> tripCode;
    cin.ignore();
    cout << "Enter Driver Name: ";
    getline(cin, driverName);
    cout << "Enter Bus Number: ";
    getline(cin, busNumber);
    cout << "Enter Revenue: ";
    cin >> revenue;
}

void cInnerCityTrip::input() {
    cout << "\n--- Inner-city Trip Input ---\n";
    cTrip::input();
    cout << "Enter Route Number: ";
    cin >> routeNumber;
    cout << "Enter Kilometers Driven: ";
    cin >> kmDriven;
}

void cInterCityTrip::input() {
    cout << "\n--- Inter-city Trip Input ---\n";
    cTrip::input();
    cin.ignore();
    cout << "Enter Destination: ";
    getline(cin, destination);
    cout << "Enter Days Driven: ";
    cin >> daysDriven;
}

istream& operator>>(istream& is, cTrip& t) {
    t.input(); 
    return is;
}