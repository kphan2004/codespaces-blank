// carWash.h
#ifndef CARWASH_H
#define CARWASH_H


class CarWash {
    private:
        // Basic data for each car in the simulation
      int carNumber;    // Car #
      int arrivalTime;  // Time car arrives
      int startTime;    // Time car starts washing
      int departureTime;    // Time car finishes washing
      int waitTime;     // Time spent for waiting
      int totalTime;    // Total time car wash
      const static int WASH_DURATION = 3;   // Wash duration is 3 minutes
      
    public:
    // Constructor
       CarWash(int num, int arrival);\

       // Getters
       int getCarNumber();
       int getArrivalTime();
       int getStartTime();
       int getDepartureTime();
       int getWaitTime();
       int getTotalTime();
       
       // Setters
       void setCarNumber(int num);
       void setArrivalTime(int arrival);
       void setStartTime(int start);
       void setDepartureTime(int depart);
       void setWaitTime(int wait);
       void setTotalTime(int total);
    
        // Calculates departure, wait, and total times
       void calculateTimes();
};

#endif