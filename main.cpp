#include <iostream>

#include "Database.h"

using namespace std;

double Terminal::parkingPrice = 5;
int main() {
    Passenger obj("Oleg Oksg",12342343);
    Terminal term("TermX", "Bor");
    Airplane airpl("AirPlaneX", "modelX");
    Date date(13, 22, 13, 2);
    Date date2(100, 2, 14, 2); // ������ "100 �����" ����� "0" �� ����������� �������. 
    Ticket ticket(3232, 33, 32, obj, airpl, term, date, date2);
    
    /*string name, airplane = "Airplane", model = "Model", terminal = "F", airport = "Boryspil";
    int passportId, flightNum, ticketId, day1, month1, hours1, minutes1;
    double price = 10.5;
    cout << "Input your Name and Surname: ";
    getline(cin, name);
    cout << "Input your Passpot Id: ";
    cin >> passportId;
    Passenger pas1(name, passportId);
    cout << "Enter date of flyout(DD MM HH mm): ";
    cin >> day1 >> month1 >> hours1 >> minutes1;
    Date dt1(minutes1, hours1, day1, month1);
    cout << "Arrival Time: " << dt1.getDay()+1 << " " << dt1.getmonth() << " " << dt1.getHours()+3 << " " << dt1.getMinutes() << endl;
    Date dt2(dt1.getMinutes(), dt1.getHours()+3, dt1.getDay()+1, dt1.getmonth());
    cout << "Enter Flight Number: ";
    cin >> flightNum;
    cout << "Enter Ticket Id: ";
    cin >> ticketId;
    Terminal term1(terminal, airport);
    Airplane airpl1(airplane, model);*/
    
    
    //Ticket ticket1(ticketId, flightNum, price, pas1, airpl1, term1, dt1, dt2);
    cout << "------Ticket 1------" << endl;
    //ticket.dataOutput();
    cout << "--------------------" << endl;
    cout << "------Ticket 2------" << endl;
    //ticket1.dataOutput();
    
    return 0;
}