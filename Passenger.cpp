#include "Passenger.h"

using namespace std;

Passenger::Passenger() {
    name = "NoName NoName";
    passportId = 0;
}

Passenger::Passenger(string name_, int passportId_) {
    regex nameExpr("^([a-zA-Z]{2,}\\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\\s?([a-zA-Z]{1,})?)");
    if (regex_match(name_, nameExpr)) {
        name = name_;
    }
    else {
        name = "NoName NoName";
        cout << "Name ans Surname wrong input(replaced with: \"NoName NoName\")" << endl;
    }

    regex passportExpr("([1-9][0-9]{8})");
    if (regex_match(to_string(passportId_), passportExpr)) {
        passportId = passportId_;
    }
    else {
        passportId = 0;
        cout << "Passport Id wrong input(replaced with: 0)" << endl;
    }
}

Passenger::Passenger(Passenger& pas) :name(pas.name), passportId(pas.passportId) {};

Passenger& Passenger::setName(string name_) {
    name = name_;
    return *this;
}

Passenger& Passenger::setPassportId(int passportId_) {
    passportId = passportId_;
    return *this;
}

string Passenger::getName() const {
    return name;
}

int Passenger::getPassportId() const {
    return passportId;
}

int Passenger::operator==(const Passenger& passenger_) {
    return (name == passenger_.name) && (passportId == passenger_.passportId);
}

int Passenger::operator!=(const Passenger& passenger_) {
    return !(*this->operator==(passenger_));
}

void Passenger::info() {
    cout << "Name: " << name << endl;
    cout << "Passport ID: " << passportId << endl;
}



