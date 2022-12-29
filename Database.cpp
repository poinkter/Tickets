#include <iostream>
#include <vector>
#include <algorithm>

#include "Database.h"

void Database<Ticket>::addTicket(const Ticket& ticket_){
    tickets.push_back(ticket_);
}

void Database<Ticket>::deleteTicket(int index){
    if(tickets.size() >= index || index < 0){
        return;
    }
    tickets.erase(tickets.begin() + index);
}

Ticket& Database<Ticket>::findTicket(const Ticket& ticket){
    find(tickets.begin(), tickets.end(), ticket);
}

void Database<Ticket>::dataOutput(){
    for (auto ticket = tickets.cbegin(); ticket != tickets.cend(); ++ticket) {
        cout << *ticket;
        cout << "--------------" << endl;
    }
}

Ticket& Database<Ticket>::operator[](int i){
    if (tickets.size() >= i || i < 0){
        return tickets[i];
    }
    cout << "No such element" << endl;
    exit(1);
}

template <typename T>
void Database<T>::addTicket(const T& ticket_){
    tickets.push_back(ticket_);
}

template <typename T>
void Database<T>::deleteTicket(int index){
    if(tickets.size() >= index || index < 0){
        return;
    }
    tickets.erase(tickets.begin() + index);
}

template<typename T>
T& Database<T>::findTicket(const T& ticket){
    find(tickets.begin(), tickets.end(), ticket);
}

template <typename T>
void Database<T>::dataOutput(){
    for (auto ticket = tickets.cbegin(); ticket != tickets.cend(); ++ticket) {
        cout << *ticket;
        cout << "--------------" << endl;
    }
}

template <typename T>
T& Database<T>::operator[](int i){
    if (tickets.size() >= i || i < 0){
        return tickets[i];
    }
    cout << "No such element" << endl;
    exit(1);
}