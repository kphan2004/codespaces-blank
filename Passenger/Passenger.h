#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    private:
         std::string FName;
         std::string LName;
         std::string seatNumber;
         std::string flightNumber;
         std::string classOfService;

    public:
        Passenger (std::string FName, std::string LName, std::string seatNumber, 
        std::string flightNumber, std::string classOfService);

        std::string getFName() const;
        void setFName(std::string const &FName);

        std::string getLName() const;
        void setLName( std::string const &LName);

        std::string getSeatNumber() const;
        void setSeatNumber( std::string const &seatNumber);

        std::string getFlightNumber() const;
        void setFlightNumber( std::string const &flightNumber);

        std::string getClassOfService() const;
        void setClassOfService( std::string const &classOfService);


};

#endif // end of Passenger