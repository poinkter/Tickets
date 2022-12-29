#pragma once
class Date {
    int minutes;
    int hours;
    int day;
    int month;
public:
    Date();
    Date(int, int, int, int);
    Date(Date&);

    inline int getMinutes() const;
    inline int getHours() const;
    inline int getDay() const;
    inline int getmonth() const;

    Date& setMinutes(int);
    Date& setHours(int);
    Date& setDay(int);
    Date& setMonth(int);

    Date operator=(const Date&);
    Date operator++(int);
    Date& operator++();
    Date operator--(int);
    Date& operator--();

    inline bool test(int, int, int);
    inline void printDate() const;

    ~Date() {};
};