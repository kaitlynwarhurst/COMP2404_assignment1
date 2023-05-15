#include "Room.h"

Room::Room(int roomNum, string bType, int cap, bool fridge){
    roomNumber = roomNum;
    bedType = bType;
    capacity = cap;
    hasFridge = fridge;
    numReservations = 0;
    
}

int Room::getRoomNumber(){
    return roomNumber;
}

Room::~Room(){
    for(int i= 0; i< numReservations; ++i){
        delete reservationsArray[i];
    }
}

bool Room::isMatch(string bt, int cap, bool f){
    if(f){
        if(!hasFridge) return false;
    }
    if(bt==bedType && capacity >= cap) return true;
    return false;
}

bool Room::lessThan(Room& r){
    if(roomNumber < r.getRoomNumber()) return true;
    return false;
}

bool Room::addReservation(string customerName, Date& d, int duration){
    if(numReservations == MAX_RES) return false;
    Reservation* r= new Reservation(customerName, d, duration); 
    if(numReservations == 0){
        reservationsArray[0] = r;
        ++numReservations;
        return true;
    }
    int i;

    for(i=0; i< numReservations; ++i){
        if(r->overlaps(*reservationsArray[i])){ 
            delete r;
            return false;
        }
        if(r->lessThan(*reservationsArray[i])){
            if(i+1 ==numReservations){
                reservationsArray[numReservations]= r;
                ++numReservations;
                return true;
            }
            if(reservationsArray[i+1]->overlaps(*r)){
                delete r;
                return false;
            }
            break;
        }
    }
    for(int j=numReservations;j>i;j--){
        reservationsArray[j] = reservationsArray[j-1];
    }
    reservationsArray[i] = r;
    ++numReservations;
    return true;
}

void Room::print(){
    cout<< "Room: " << roomNumber << " Bed type: " << bedType << " Capacity: " << capacity << " Has fridge: " << hasFridge << " number of reservations " << numReservations <<endl;
}

void Room::printReservations(){
    print();
    cout<< "Reservations: " << endl;
    for(int i =0; i< numReservations; i++){
        reservationsArray[i]->print();
    } 
}