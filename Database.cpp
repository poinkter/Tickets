#include <iostream>

#include "Database.h"

template<>
void Database::addTicket(const Ticket& ticket_){
    tickets.push_back(ticket_);
}

template<>
void Database::deleteTicket(int index){
    if(tickets.size() >= index || index < 0){
        return;
    }
    tickets.erase(tickets.begin() + index);
}

template<>
void Database::dataOutput(){
    for(const Ticket& ticket: tickets){
        cout << ticket;
        cout << "--------------------" << endl << endl;
    }
}

template<>
Ticket& Database::operator[](int i){
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

template <typename T>
void Database<T>::dataOutput(){
    for(const Ticket& ticket: tickets){
        cout << ticket;
        cout << "--------------------" << endl << endl;
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