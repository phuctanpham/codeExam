// cTrips_constructors.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"

cTrip::cTrip() : tripCode(""), driverName(""), busNumber(""), revenue(0.0) {}
cTrip::cTrip(string code, string name, string bus, double rev)
    : tripCode(code), driverName(name), busNumber(bus), revenue(rev) {}

cInnerCityTrip::cInnerCityTrip() : cTrip(), routeNumber(0), kmDriven(0.0f) {}
cInnerCityTrip::cInnerCityTrip(string code, string name, string bus, double rev, int route, float km)
    : cTrip(code, name, bus, rev), routeNumber(route), kmDriven(km) {}

cInterCityTrip::cInterCityTrip() : cTrip(), destination(""), daysDriven(0) {}
cInterCityTrip::cInterCityTrip(string code, string name, string bus, double rev, string dest, int days)
    : cTrip(code, name, bus, rev), destination(dest), daysDriven(days) {}