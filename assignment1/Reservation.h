#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Date.h"

class Reservation {
    public:
        //constructor
        Reservation() = default;
        Reservation(string customerName, Date& checkIn, int duration);
        void setDuration(int duration=1);
        bool overlaps(Reservation& r);
        bool lessThan(Reservation& res);
        bool lessThan(Date& d);
        void print();


    private: 
        Date checkInDate;
        string customerName;
        int duration;


};

#endif