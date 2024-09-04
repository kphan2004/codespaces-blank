#include "Passenger.h"


// constrction
Passenger::Passenger (std::string FName, std::string LName, std::string seatNumber, 
        std::string flightNumber, std::string classOfService) {
        this->FName = FName;
        this->LName = LName;
        this->seatNumber = seatNumber;
        this->flightNumber = flightNumber;
        this->classOfService = classOfService;

    }

std::string Passenger::getFName() const {
    return FName;
}
void Passenger::setFName(std::string const &FName) {
    this->FName = FName;
}

std::string Passenger::getLName() const {
    return LName;
}
void Passenger::setLName(std::string const &LName) {
    this->LName = LName;
}

std::string Passenger::getSeatNumber() const {
    return seatNumber;
}
void Passenger::setSeatNumber(std::string const &seatNumber) {
    this->seatNumber = seatNumber;
}

std::string Passenger::getFlightNumber() const {
    return flightNumber;
}
void Passenger::setFlightNumber(std::string const &flightNumber) {
    this->flightNumber = flightNumber;
}

std::string Passenger::getClassOfService() const {
    return classOfService;
}
void Passenger::setClassOfService(std::string const &classOfService) {
    this->classOfService = classOfService;
}