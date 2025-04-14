// carWash.h
#ifndef CARWASH_H
#define CARWASH_H


class CarWash {
    private:
      int carNumber;
      int arrivalTime;
      int startTime;
      int departureTime;
      int waitTime;
      int totalTime;
      const static int WASH_DURATION = 3;
      
    public:
       CarWash(int num, int arrival);
       int getCarNumber();
       int getArrivalTime();
       int getStartTime();
       int getDepartureTime();
       int getWaitTime();
       int getTotalTime();
       
       void setCarNumber(int num);
       void setArrivalTime(int arrival);
       void setStartTime(int start);
       void setDepartureTime(int depart);
       void setWaitTime(int wait);
       void setTotalTime(int total);

       void calculateTimes();
};

#endif