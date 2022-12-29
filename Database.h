#include <string>
#include <vector>

#include "Ticket.h"

using namespace std;

template<>
class Database{
    vector<Ticket> tickets;
public:
    void addTicket(const Ticket&);
    void deleteTicket(int);
    //Ticket& findTicket(string, int);

    inline void dataOutput();

    Ticket& operator[](int);

    ~Database(){};
};

template<typename T>
class Database{
    vector<T> tickets;
public:
    void addTicket(const T&);
    void deleteTicket(int);
    //Ticket& findTicket(string, int);

    inline void dataOutput();

    T& operator[](int);

    ~Database(){};
};