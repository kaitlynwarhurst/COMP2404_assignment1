#include "Hotel.h"

Hotel::Hotel(){
    numRooms = 0;
}

Hotel::~Hotel(){
    for(int i= 0; i< numRooms; ++i){
        delete roomArray[i];
    }
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
    if(MAX_ROOMS <= numRooms) return false;
    for(int i=0; i< numRooms;i++){
        if(roomArray[i]->getRoomNumber() == roomNumber) return false;
    }
    Room* r = new Room(roomNumber, bedType, capacity, fr);
    if(numRooms == 0){
        roomArray[0] = r;
        ++ numRooms;
        return true;
    }
    //r->print();
    int index = 0;
    //finds the right index for Room
    while (index < numRooms){
        if(r->lessThan(*roomArray[index])){
            break;
        }
        ++index;
    }

    for (int i = numRooms; i > index; --i){
        roomArray[i] = roomArray[i-1];
    }

    roomArray[index] = r;

    ++ numRooms;
    return true;
}

bool Hotel::deleteRoom(int roomNumber){
    int i =0; 
    while(roomNumber != roomArray[i]->getRoomNumber() && i <numRooms){
        ++i;
    }
    if(i == numRooms) return false;

    roomArray[i]->~Room();
    while(i<numRooms -1){
        roomArray[i] = roomArray[i+1];
        ++i;
    }
    --numRooms;
    return true;
}

bool Hotel::getRoom(int roomNumber, Room** room){
   // Room** r;

    for(int i=0; i<numRooms; i++){
        if(roomNumber == roomArray[i]->getRoomNumber()){
            *room = roomArray[i];
            return true;
        }
    }
    return false;
}

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    if(numRooms == 0) return false;
    for(int i= 0; i<numRooms; ++i){
        if(roomArray[i]->isMatch(bedType, capacity, fr)){
            //cout<< i<<endl;
            if(roomArray[i]->addReservation(customer, date,duration)) return true;

        }
    }
    return false;
}

void Hotel::print(){
    //cout<<"Rooms: "<< endl;
    //cout<< "Possible error 1" <<endl;
    for(int i=0; i< numRooms; i++){
        roomArray[i]->print();
    }
    //cout<< "Possible error 2" <<endl;
}

void Hotel::printReservations(){
    //cout<<"Rooms: "<< endl;
    for(int i=0; i< numRooms; i++){
        roomArray[i]->printReservations();
    }
    //cout <<"error here" <<endl;
}

void Hotel::updateReservations(Date& currentDate){

}
