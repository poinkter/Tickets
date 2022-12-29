#pragma once
#include "Ticket.h"

using namespace std;

template<typename T>
class Database {
    vector<T> tickets;
public:
    void addTicket(const T&);
    void deleteTicket(int);
    T& findTicket(const T&);

    inline void dataOutput();

    T& operator[](int);

    ~Database() {};
};

template<>
class Database<Ticket> {
    vector<Ticket> tickets;
public:
    void addTicket(const Ticket&);
    void deleteTicket(int);
    Ticket& findTicket(const Ticket&);

    inline void dataOutput();

    Ticket& operator[](int);

    ~Database() {};
};
