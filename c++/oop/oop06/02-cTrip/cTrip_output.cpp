// cTrip_output.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"
#include <iomanip>

void cTrip::output() const {
    cout << "Code: " << tripCode 
         << " | Driver: " << driverName 
         << " | Bus: " << busNumber 
         << " | Revenue: " << fixed << setprecision(2) << revenue;
}

void cInnerCityTrip::output() const {
    cout << "[Inner-City] ";
    cTrip::output();
    cout << " | Route: " << routeNumber 
         << " | KM: " << kmDriven << endl;
}

void cInterCityTrip::output() const {
    cout << "[Inter-City] ";
    cTrip::output();
    cout << " | Dest: " << destination 
         << " | Days: " << daysDriven << endl;
}

ostream& operator<<(ostream& os, const cTrip& t) {
    t.output(); 
    return os;
}