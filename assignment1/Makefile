all: ass1

ass1: main.cc Room.o Date.o Reservation.o Hotel.o
	g++ -o ass1 main.cc Date.o Room.o Reservation.o Hotel.o

Room.o: Room.h Room.cc 
	g++ -c Room.cc 

Reservation.o: Reservation.h Reservation.cc 
	g++ -c Reservation.cc 

Date.o: Date.h Date.cc 
	g++ -c Date.cc

Hotel.o: Hotel.h Hotel.cc
	g++ -c Hotel.cc

clean:
	rm -f ass1 *.o 