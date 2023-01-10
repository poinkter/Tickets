#include <string>
#include <regex>
#include <iostream>

#include "Ticket.h"

using namespace std;

Ticket::Ticket() :passenger(), departTime(), arrivalTime(), airplane(), terminal(){
    ticketId = 0;
    flightNum = 0;
    price = 0;

}

Ticket::Ticket(int ticketId_, int flightNum_, double price_, Airplane &airplane_, Terminal &terminal_, Date &departTime_, Date &arrivalTime_)
              :passenger(), airplane(airplane_), terminal(terminal_), departTime(departTime_), arrivalTime(arrivalTime_) {
    regex ticketIdExpr ("([1-9]{2}[0-9]{4})");
    if(regex_match(to_string(ticketId_), ticketIdExpr)){
        ticketId = ticketId_;
    }
    else{ ticketId = 0;
          cout << "Ticket Id wrong input(replaced with: 0)" << endl; 
    }
    if (flightNum_ > 0){
        flightNum = flightNum_;
    }
    else{ flightNum = 0; 
          cout << "Flight number wrong input(replaced with: 0)" << endl;      
    }
    if (price_ > 0){
        price = price_;
    }
    else{ price = 0; 
          cout << "Price wrong input(replaced with: 0)" << endl;
    }
}

Ticket::Ticket(int ticketId_, int flightNum_, double price_, Passenger &passenger_, Airplane &airplane_, Terminal &terminal_, Date &departTime_, Date &arrivalTime_)
    : passenger(passenger_), airplane(airplane_), terminal(terminal_), departTime(departTime_), arrivalTime(arrivalTime_){
    regex ticketIdExpr ("([1-9]{2}[0-9]{4})");
    if(regex_match(to_string(ticketId_), ticketIdExpr)){
        ticketId = ticketId_;
    }
    else{ ticketId = 0;
          cout << "Ticket Id wrong input(replaced with: 0)" << endl; 
    }
    if (flightNum_ > 0){
        flightNum = flightNum_;
    }
    else{ flightNum = 0; 
          cout << "Flight number wrong input(replaced with: 0)" << endl;      
    }
    if (price_ > 0){
        price = price_;
    }
    else{ price = 0; 
          cout << "Price wrong input(replaced with: 0)" << endl;
    }
}

Ticket::Ticket(Passenger& passenger_): departTime(), arrivalTime(), airplane(), terminal(), passenger(passenger_){
    ticketId = flightNum = price = 0;
}

Ticket::Ticket(const Ticket& tick) :ticketId(tick.ticketId), departTime(tick.departTime), arrivalTime(tick.arrivalTime),
flightNum(tick.flightNum), price(tick.price), passenger(tick.passenger), airplane(tick.airplane), terminal(tick.terminal) {};

Ticket& Ticket::setData(int ticketId_, int flightNum_, double price_/*, Date departTime_, Date arrivalTime_*/){
    regex ticketIdExpr ("([1-9]{2}[0-9]{4})");
    if(regex_match(to_string(ticketId_), ticketIdExpr)){
        ticketId = ticketId_;
    }
    else{ ticketId = 0;
          cout << "Ticket Id wrong input(replaced with: 0)" << endl; 
    }
    //departTime = departTime_;
    //arrivalTime = arrivalTime_; //operator= for Date
    if (flightNum_ > 0){
        flightNum = flightNum_;
    }
    else{ flightNum = 0; 
          cout << "Flight number wrong input(replaced with: 0)" << endl;      
    }
    if (price_ > 0){
        price = price_;
    }
    else{ price = 0; 
          cout << "Price wrong input(replaced with: 0)" << endl;
    }
    return *this;
};

Ticket& Ticket::setPassenger(string name_, int passportId_) {
    passenger = Passenger(name_, passportId_);
    return *this;
};

Ticket& Ticket::setTicketId(int ticketId_) {
    regex ticketIdExpr ("([1-9]{2}[0-9]{4})");
    if(regex_match(to_string(ticketId_), ticketIdExpr)){
        ticketId = ticketId_;
    }
    else{ 
        ticketId = 0;
        cout << "Ticket Id wrong input(replaced with: 0)" << endl;
    }
    return *this;
}

Ticket& Ticket::setArrivalTime(Date arrivalTime_) {
    arrivalTime = arrivalTime_;
    return *this;
}

Ticket& Ticket::setDepartTime(Date departTime_) {
    departTime = departTime_;
    return *this;
}                                                     

Ticket& Ticket::setFlightNum(int flightNum_) {
    if (flightNum_ > 0){
        flightNum = flightNum_;
    }
    else{ flightNum = 0; 
          cout << "Flight number wrong input(replaced with: 0)" << endl;  
    }
    return *this;
}

Ticket& Ticket::setPrice(double price_) {
    if (price_ > 0){
        price = price_;
    }
    else{ price = 0; 
          cout << "Price wrong input(replaced with: 0)" << endl;  
    }
    return *this;
}

int Ticket::getTicketId() const{
    return ticketId;
}

Date Ticket::getArrivalTime() {
    return arrivalTime;
}

Date Ticket::getDepartTime() {
    return departTime;
}

int Ticket::getFlightNum() const{
    return flightNum;
}

double Ticket::getPrice() const{
    return price;
}

string Ticket::getPassenger() const{
    return passenger.getName() + " " + to_string(passenger.getPassportId());
}

string Ticket::getAirportName() const{
    return terminal.getAirportName() + " " + terminal.getTerminalName();
}

bool Ticket::operator==(const Ticket& ticket_) {
    return ticketId == ticket_.ticketId && passenger == ticket_.passenger;
}

Ticket& Ticket::operator+(const Ticket &ticket_){// a + b + c
    price += ticket_.price;
    return *this;
}

int Ticket::operator<(const Ticket& ticket_) const{
    return price < ticket_.price;
}

int Ticket::operator>(const Ticket& ticket_) const{
    return ticket_ < *this;//!(*this < ticket_ || *this == ticket_);
}

Ticket::operator Passenger(){
    Passenger passenger_(passenger);
    return passenger_;
}

ostream& operator<<(ostream& out, const Ticket& ticket_){// this << cout
    out << "Ticket ID: " << ticket_.ticketId << endl;
    out << "Flight Number: " << ticket_.flightNum << endl;
    out << "Total price: " << ticket_.price + ticket_.terminal.getParkingPrice() << endl;
    out << "Passenger Name: " << ticket_.passenger.getName() << endl;
    out << "Passenger PassportId:" << ticket_.passenger.getPassportId() << endl;
    out << "Airplane Company:" << ticket_.airplane.getCompany() << endl;
    out << "Airplane model: " << ticket_.airplane.getModel() << endl;
    out << "Airport name: " << ticket_.terminal.getAirportName() << endl;
    out << "Terminal name: " << ticket_.terminal.getTerminalName() << endl;
    out << "Terminal Parking price: " << ticket_.terminal.getParkingPrice() << endl;
    out << "Depart time: " << endl;
    ticket_.departTime.printDate();
    out << "Arrival time: " << endl;
    ticket_.arrivalTime.printDate();
    return out;
}

istream& operator>>(istream& in, Ticket& ticket_){
    string temp1, temp2;
    int temp3, temp4, temp5, temp6;
    cout << "Enter ticketId (e.g. 110000): "; 
    in >> ticket_.ticketId;
    cout << "Enter flight Number: "; 
    in >> ticket_.flightNum;
    cout << "Enter ticket price: "; 
    in >> ticket_.price;
    cout << "Enter Name and Surname: "; 
    getline(in, temp1);
    cout << "Enter passportId (e.g. 127527483): "; 
    in >> temp3;
    ticket_.setPassenger(temp1, temp3);
    cout << "Enter airplane company: "; 
    in >> temp1;
    cout << "Enter airplane model: "; 
    in >> temp2;
    ticket_.airplane.setCompany(temp1);
    ticket_.airplane.setModel(temp2);
    cout << "Enter airport name: "; 
    in >> temp1;
    ticket_.terminal.setAirportName(temp1);
    cout << "Enter terminal: "; 
    in >> temp1;
    ticket_.terminal.setTerminalName(temp1);
    cout << "Enter depart time in format MM DD HH mm: ";
    in >> temp3 >> temp4 >> temp5 >> temp6;
    Date dt1(temp3, temp4, temp5, temp6);
    ticket_.setDepartTime(dt1);
    cout << "Enter depart time in format MM DD HH mm: ";
    in >> temp3 >> temp4 >> temp5 >> temp6;
    Date dt2(temp3, temp4, temp5, temp6);
    ticket_.setArrivalTime(dt2);
    return in;
}