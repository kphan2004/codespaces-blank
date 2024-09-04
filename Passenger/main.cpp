#include <iostream>
#include "Passenger.h"

int main () {

    std::string firstName, lastName, seatNumber, flightNumber, classOfService;

    std::cout << " Write your First Name: ";
    std::getline(std::cin, firstName);

    std::cout << " Write your Last Name: ";
    std::getline(std::cin, lastName);

    std::cout << " Write your Seat Number: ";
    std::getline(std::cin, seatNumber);

    std::cout << " Write your Flight Number: ";
    std::getline(std::cin, flightNumber);

    std::cout << " Class of Service: ";
    std::getline(std::cin, classOfService);

    Passenger passenger(firstName, lastName, seatNumber, flightNumber, classOfService);

    std::cout << "\n Passenger Details:\n";
    std::cout << "First Name: " << passenger.getFName() << std::endl;
    std::cout << "Last Name: " << passenger.getLName() << std::endl;
    std::cout << "Seat Number: " << passenger.getSeatNumber() << std::endl;
    std::cout << "Flight Number: " << passenger.getFlightNumber() << std::endl;
    std::cout << "Class of Service: " << passenger.getClassOfService() << std::endl;

    return 0;
}