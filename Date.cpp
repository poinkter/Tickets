#include <iostream>

#include "Date.h"

using std::cout; 
using std::endl;

Date::Date() {
    minutes = 0;
    hours = 0;
    day = 0;
    month = 0;
}

Date::Date(int minutes_, int hours_, int day_, int month_) {
    setMinutes(minutes_);
    setHours(hours_);
    setDay(day_);
    setMonth(month_);
}

Date::Date(const Date& date) :minutes(date.minutes), hours(date.hours), day(date.day), month(date.month) {};

Date& Date::setMinutes(int minutes_) {
    test(minutes_, 0, 59) ? minutes = minutes_ : minutes = 0;
    return *this;
}

Date& Date::setHours(int hours_) {
    test(hours_, 0, 23) ? hours = hours_ : hours = 0;
    return *this;
}

Date& Date::setDay(int day_) {
    test(day_, 1, 31) ? day = day_ : day = 0;
    return *this;
}

Date& Date::setMonth(int month_) {
    test(month_, 1, 12) ? month = month_ : month = 0;
    return *this;
}

int Date::getMinutes() const{
    return minutes;
}

int Date::getHours() const{
    return hours;
}

int Date::getDay() const{
    return day;
}

int Date::getmonth() const{
    return month;
}

Date Date::operator=(const Date& date_){
    if (this != &date_){
        month = date_.month;
        day = date_.day;
        hours = date_.hours;
        minutes = date_.minutes;
    }
    return *this;
}

Date Date::operator++(int i){
    Date temp = *this;
    day++;
    if (day == 32){
        month++;
        if (month == 13){
            month = 1;
        }
        day = 1;
    }
    return temp;
}

Date& Date::operator++(){
    ++day;
    if (day == 32){
        month++;
        if (month == 13){
            month = 1;
        }
        day = 1;
    }
    return *this;
}

Date Date::operator--(int i){
    Date temp = *this;
    day--;
    if (day == 0){
        month--;
        if (month == 0){
            month = 12;
        }
        day = 31;
    }
    return temp;
}

Date& Date::operator--(){
    --day;
    if (day == 0){
        month--;
        if (month == 0){
            month = 12;
        }
        day = 31;
    }
    return *this;
}

//test for correct values in Date
bool Date::test(int value, int start, int end) { // ��������������� ������� ��� �������� ����� ����� 
        if (value >=start && value <= end) {
            return true;
        }
    return false;
}

void Date::printDate() const{
    cout << "Time: " << month << "/" << day << "  " << hours << ":" << minutes << endl;
}