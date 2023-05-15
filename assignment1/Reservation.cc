#include "Reservation.h"

Reservation::Reservation(string cName, Date& checkIn, int d){
    customerName = cName;
    checkInDate = checkIn;
    duration = d;
}

void Reservation::setDuration(int duration){
    duration = duration;
}

bool Reservation::overlaps(Reservation& r){
    if(checkInDate.equals(r.checkInDate)) return true;
    //if this date is before r.date
    bool before = checkInDate.lessThan(r.checkInDate);
    //temp variables to hold the dates
    Date a = checkInDate;
    Date b = r.checkInDate; 

    a.addDays(duration);
    //if it is before the days are added and after days are added to the duration
    if((a.lessThan(b)||a.equals(b))&&before) return false;
    //
    if(!(a.lessThan(b))&&before) return true;

    b.addDays(r.duration); 

    if(!before && (b.lessThan(checkInDate)||b.equals(checkInDate))) return false;

    return true;
}

bool Reservation::lessThan(Reservation& res){
    if(overlaps(res)) return false;
    if(lessThan(res.checkInDate)) return true;
    return false; 
}

bool Reservation::lessThan(Date& d){
    Date a = checkInDate;
    if(!a.lessThan(d)) return false;
    a.addDays(duration);
    if(!a.lessThan(d)) return false;
    return true;
}

void Reservation::print(){
    cout<< "Reservation for "<< customerName << " on " ;
    checkInDate.print();
    cout << " for " << duration << " days." <<endl;
}