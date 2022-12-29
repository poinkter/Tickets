#include <string>

#include "Passenger.h"
#include "Date.h"
#include "Airport.h"

using namespace std;

class Ticket {
    int ticketId;
    int flightNum;
    double price;
    Date departTime;
    Date arrivalTime;
    Passenger passenger;
    Airplane airplane;
    Terminal terminal;
public:
    Ticket();
    Ticket(int, int, double, Airplane&, Terminal&, Date&, Date&);
    Ticket(int, int, double, Passenger&, Airplane&, Terminal&, Date&, Date&);
    Ticket(Passenger&);
    Ticket(Ticket&);

    Ticket& setTicketId(int);
    Ticket& setDepartTime(Date);
    Ticket& setArrivalTime(Date);
    Ticket& setFlightNum(int);
    Ticket& setPrice(double);

    Ticket& setData(int, int, double);
    Ticket& setPassenger(string, int);

    inline int getTicketId() const;
    inline Date getArrivalTime();
    inline Date getDepartTime();
    inline int getFlightNum() const;
    inline double getPrice() const;

    Ticket& operator+(const Ticket&);
    int operator<(const Ticket&);
    int operator>(const Ticket&);
    operator Passenger();

    //inline void dataOutput();
    friend ostream& operator<<(ostream&, const Ticket&);
    friend istream& operator>>(istream&, Ticket&);

    ~Ticket(){};
};