// carWash.cpp
#include "carWash.h"

// Constructor
CarWash::CarWash(int num, int arrival) : carNumber(num), arrivalTime(arrival),
                    startTime(0), departureTime(0), waitTime(0), totalTime(0) {

}

int CarWash::getCarNumber() {
    return carNumber;
}
int CarWash::getArrivalTime() {
    return arrivalTime;
}
int CarWash::getStartTime() {
    return startTime;
}
int CarWash::getDepartureTime() {
    return departureTime;
}
int CarWash::getWaitTime() {
    return waitTime;
}
int CarWash::getTotalTime() {
    return totalTime;
}
       
void CarWash::setCarNumber(int num) {
    carNumber = num;
}
void CarWash::setArrivalTime(int arrival) {
    arrivalTime = arrival;
}
void CarWash::setStartTime(int start) {
    startTime = start;
}
void CarWash::setDepartureTime(int depart) {
    departureTime = depart;
}
void CarWash::setWaitTime(int wait) {
    waitTime = wait;
}
void CarWash::setTotalTime(int total) {
    totalTime = total;
}

void CarWash::calculateTimes() {
    departureTime = startTime + WASH_DURATION;
    waitTime = startTime - arrivalTime;
    totalTime = departureTime - arrivalTime;
}