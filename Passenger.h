#pragma once

#include <string>

using namespace std;

class Passenger {
    string name;
    int passportId;
public:
    Passenger();
    Passenger(string, int);
    Passenger(const Passenger&);

    inline string getName() const;
    inline int getPassportId() const;

    Passenger& setName(string);
    Passenger& setPassportId(int);

    int operator==(const Passenger&);
    int operator!=(const Passenger&);

    inline void info();

    ~Passenger(){};
};