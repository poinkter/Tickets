#pragma once

#include <string>
#include <vector>

using namespace std;

template<typename T>
class Database{
    vector<T> tickets;
public:
    void addTicket(const T&);
    void deleteTicket(int);
    int findTicket(const T&);

    inline void dataOutput();

    T& operator[](int);

    ~Database(){};
};

template<>
class Database<Ticket>{
    vector<Ticket> tickets;
public:
    void addTicket(const Ticket&);
    void deleteTicket(int);
    int findTicket(const Ticket&);

    inline void dataOutput();

    Ticket& operator[](int);

    ~Database(){};
};