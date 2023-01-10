#include <iostream>

#include "Date.cpp"
#include "Airport.cpp"
#include "Passenger.cpp"
#include "Ticket.cpp"
#include "Database.cpp"

using namespace std;

double Terminal::parkingPrice = 5;
int main() {
    Passenger obj("Oleg Oksg",123423387), pas;
    Terminal term("TermX", "Bor");
    Airplane airpl("AirPlaneX", "modelX");
    Date date(13, 22, 13, 2);
    Date date2(100, 2, 14, 2), date3; 
    Ticket ticket1(323235, 33, 32, obj, airpl, term, date, date2), ticket2;
    
    cout << date++.getDay() << endl;
    ++date;
    cout << date--.getDay() << endl;

    ticket1 = ticket1 + ticket1;
    cout << ticket1.getPrice() << endl;

    cout << (ticket1 > ticket2) << endl;

    cout << (pas != obj) << endl;

    date3 = date;
    cout << date3.getDay() << endl;

    Database<Ticket> ticketSystem;
    ticketSystem.addTicket(ticket1);
    ticketSystem.addTicket(ticket2);
    cout << ticketSystem.findTicket(ticket2) << endl;
    
    Ticket ticket3(obj);
    pas = Passenger(ticket2);
    cout << ticket3.getPassenger() << endl;
    cout << pas.getName() << endl;

    Airport* airport = new Terminal("F", "Munchen");
    airport->view();

    Database<int> env;
    env.addTicket(30);
    env.addTicket(20);
    env.deleteTicket(0);

    env.dataOutput();
    
    return 0;
}