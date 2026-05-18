// cTrip_methods.cpp
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#include "cTrip.h"

// --- cTrip Base Methods ---
string cTrip::getTripCode() const { return tripCode; }
void cTrip::setTripCode(const string& code) { tripCode = code; }

string cTrip::getDriverName() const { return driverName; }
void cTrip::setDriverName(const string& name) { driverName = name; }

string cTrip::getBusNumber() const { return busNumber; }
void cTrip::setBusNumber(const string& bus) { busNumber = bus; }

double cTrip::getRevenue() const { return revenue; }
void cTrip::setRevenue(double rev) { revenue = rev; }

// --- cInnerCityTrip Methods ---
int cInnerCityTrip::getRouteNumber() const { return routeNumber; }
void cInnerCityTrip::setRouteNumber(int route) { routeNumber = route; }

float cInnerCityTrip::getKmDriven() const { return kmDriven; }
void cInnerCityTrip::setKmDriven(float km) { kmDriven = km; }

// --- cInterCityTrip Methods ---
string cInterCityTrip::getDestination() const { return destination; }
void cInterCityTrip::setDestination(const string& dest) { destination = dest; }

int cInterCityTrip::getDaysDriven() const { return daysDriven; }
void cInterCityTrip::setDaysDriven(int days) { daysDriven = days; }