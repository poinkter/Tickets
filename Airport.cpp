#include <string>
#include <iostream>

#include "Airport.h"

using std::string;
using std::cout; 
using std::endl;

Airport::Airport(){
    airportName = "NoName";
}

Airport::Airport(string airportName_){
    airportName = airportName_;
}

Airport::Airport(const Airport& airp){
    airportName = airp.airportName;
}

Airport& Airport::setAirportName(string airportName_){
    airportName = airportName_;
    return *this;
}

string Airport::getAirportName() const{
    return airportName;
}

void Airport::view(){
    cout << "Airport::view" << endl;
    cout << "Airport " << airportName << endl;
}

Terminal::Terminal():Airport(){
    terminalName = "NoName";
}

Terminal::Terminal(string terminalName_, string airport): Airport(airport){
    terminalName = terminalName_;
}

Terminal::Terminal(const Terminal& ter) :terminalName(ter.terminalName), Airport(ter){};

//----

Terminal& Terminal::setTerminalName(string terminalName_) {
    terminalName = terminalName_;
    return *this;
}

string Terminal::getTerminalName() const{
    return terminalName;

}

double Terminal::getParkingPrice(){
    return parkingPrice;
}

void Terminal::view(){
    cout << "Terminal::view" << endl;
    cout << "Terminal " << terminalName << endl;
    cout << "Parking price " << parkingPrice << endl;
}

Airplane::Airplane() {
    company = "NoName";
    model = "NoName";
}

Airplane::Airplane(string company_, string model_) {
    company = company_;
    model = model_;
}

Airplane::Airplane(const Airplane& airpl) :company(airpl.company), model(airpl.model) {};


Airplane& Airplane::setCompany(string company_) {
    company = company_;
    return *this;
}
Airplane& Airplane::setModel(string model_) {
    model = model_;
    return *this;
}

string Airplane::getCompany() const{
    return company;

}

string Airplane::getModel() const{
    return model;
}
