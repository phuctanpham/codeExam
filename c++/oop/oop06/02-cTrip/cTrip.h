// cTrip.h
/* name: Pham Tan Phuc
id: 25730134
dob: 240290
class: IT002.F21.CN1.CNTT
*/
#ifndef CTRIP_H
#define CTRIP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class
class cTrip {
protected:
    string tripCode;
    string driverName;
    string busNumber;
    double revenue;

public:
    cTrip();
    cTrip(string code, string name, string bus, double rev);
    virtual ~cTrip() {}

    // Getters and Setters - Declarations ONLY
    string getTripCode() const;
    void setTripCode(const string& code);
    
    string getDriverName() const;
    void setDriverName(const string& name);
    
    string getBusNumber() const;
    void setBusNumber(const string& bus);
    
    double getRevenue() const;
    void setRevenue(double rev);

    // Virtual I/O
    virtual void input();
    virtual void output() const;

    // Operator overloading
    friend istream& operator>>(istream& is, cTrip& t);
    friend ostream& operator<<(ostream& os, const cTrip& t);
};

// Derived class: Inner-city Trip
class cInnerCityTrip : public cTrip {
private:
    int routeNumber;
    float kmDriven;

public:
    cInnerCityTrip();
    cInnerCityTrip(string code, string name, string bus, double rev, int route, float km);
    
    // Getters and Setters - Declarations ONLY
    int getRouteNumber() const;
    void setRouteNumber(int route);
    
    float getKmDriven() const;
    void setKmDriven(float km);

    void input() override;
    void output() const override;
};

// Derived class: Inter-city Trip
class cInterCityTrip : public cTrip {
private:
    string destination;
    int daysDriven;

public:
    cInterCityTrip();
    cInterCityTrip(string code, string name, string bus, double rev, string dest, int days);
    
    // Getters and Setters - Declarations ONLY
    string getDestination() const;
    void setDestination(const string& dest);
    
    int getDaysDriven() const;
    void setDaysDriven(int days);

    void input() override;
    void output() const override;
};

#endif // CTRIP_H