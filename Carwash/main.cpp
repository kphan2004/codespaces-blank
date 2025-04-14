// main.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include "carWash.h"

using namespace std;

const int SIMULATION_END_TIME = 540;

int main() {
    ifstream infile("arrival_time.txt");
    if (!infile) {
        cerr << "ERROR opening arrival_time.txt\n";
        return 1;
    }

    queue<CarWash> carQueue;
    int carNumber = 1;
    int time;

    while (infile >> time) {
        if (time <= SIMULATION_END_TIME) {
            carQueue.push(CarWash(carNumber++, time));
        }
        
    }

    cout << "Opening Time: 8:00 AM (0 minutes)\n";
    cout << "Closing Time: 5:00 PM (" << SIMULATION_END_TIME << " minutes)\n";
    cout << "\nStart of Simulation\n";

    cout << left << setw(15) << "Car number" << setw(15) << "Arrival Time"
         << setw(15) << "Start Time" << setw(20) << "Departure Time"
         << setw(12) << "Wait Time" << setw(12) << "Total Time" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    
    
    int currentTime = 0;
    int totalWait = 0;
    int totalCharge = 0;
    int servedCars = 0;
    int totalCarWashUseTime =0;

    while (!carQueue.empty()) {
        CarWash car = carQueue.front();
        carQueue.pop();

        int arrival = car.getArrivalTime();
        int startTime = max(arrival, currentTime);
        car.setStartTime(startTime);
        car.calculateTimes();

        currentTime = car.getDepartureTime();
        totalWait += car.getWaitTime();
        totalCharge += 3;
        totalCarWashUseTime += car.getTotalTime();
        servedCars++;

        cout << left << setw(15) << car.getCarNumber()
             << setw(15) << car.getArrivalTime()
             << setw(15) << car.getStartTime()
             << setw(20) << car.getDepartureTime()
             << setw(12) << car.getWaitTime()
             << setw(12) << car.getTotalTime() << endl;
             
        }
    cout << "Car " << carNumber++ << " arrived after closing time and was not served.\n";
    cout << "End of Simulation\n\n";
    cout << "Statistics:\n";
    cout << "Total Wait Time: " << totalWait << " minutes\n";

    int averageMin = servedCars > 0 ? totalWait / servedCars : 0;
    int averageSec = servedCars > 0 ? (totalWait * 60 / servedCars) % 60 : 0;
    cout << "Average Wait Time: " << averageMin << " minutes and " << averageSec << " seconds\n";

    cout << "Total car wash use time: " << totalCarWashUseTime << " minutes\n";

    cout << fixed << setprecision(2);
    cout << "Percentage of time car was was in use: " 
         << (totalCharge * 100.0 / SIMULATION_END_TIME) << "%\n";

    return 0;
}
