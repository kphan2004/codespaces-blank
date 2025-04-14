



// main.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>
#include "carWash.h"

using namespace std;

const int SIMULATION_END_TIME = 540; // 9 hours * 60 minutes

int main() {   
    // File arrival_time.txt, open to check all number and calculate quantity of cars and washing cars
    ifstream infile("arrival_time.txt");    // Open file with arrival times
    if (!infile) { 
        cerr << "ERROR opening arrival_time.txt\n";     // Show error if file missing
        return 1;   // Exit the program
    }
    // Queue to hold arriving cars
    queue<CarWash> carQueue;    
    int carNumber = 1; // Car counter
    int time;

    // read and enqueue cars that arrive on time
    while (infile >> time) {
        if (time <= SIMULATION_END_TIME) {
            carQueue.push(CarWash(carNumber++, time)); // Only queue cars that arrive on time
        }
        // Car arriving after close time are ignored here to reported later
    }

    // Display headers
    cout << "Opening Time: 8:00 AM (0 minutes)\n";
    cout << "Closing Time: 5:00 PM (" << SIMULATION_END_TIME << " minutes)\n";
    // Start 0f simulation
    cout << "\nStart of Simulation\n";

    cout << left << setw(15) << "Car number" << setw(15) << "Arrival Time"
         << setw(15) << "Start Time" << setw(20) << "Departure Time"
         << setw(12) << "Wait Time" << setw(12) << "Total Time" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    
    // Initialize simulation statistics
    int currentTime = 0;    // Tracks current time of wash
    int totalWait = 0;      // Sum of all car wait times
    int totalCharge = 0;    // Total washing time
    int servedCars = 0;     // Number of cars served
    int totalCarWashUseTime =0;     // Sum of all time the car wash was actively

    // Process the queue
    while (!carQueue.empty()) {
        CarWash car = carQueue.front();     // Get the next car
        carQueue.pop();     // Remove from queue

        // Set start time as thelater of arrival or current wash available time
        int arrival = car.getArrivalTime();     // Get arrival time
        int startTime = max(arrival, currentTime);  // Start time is either arrival
        car.setStartTime(startTime);
        car.calculateTimes();   // Automatically calculates other times

        // Update simulation clock and totals
        currentTime = car.getDepartureTime();   // Update time when wash next available 
        totalWait += car.getWaitTime(); // Add to total wait
        totalCharge += 3;   // 3 mins wash time
        totalCarWashUseTime += car.getTotalTime();  // Add to usage time
        servedCars++;   // Increment number of cars served

        // Print details for the car
        cout << right << setw(9) << car.getCarNumber()
             << setw(15) << car.getArrivalTime()
             << setw(15) << car.getStartTime()
             << setw(18) << car.getDepartureTime()
             << setw(15) << car.getWaitTime()
             << setw(13) << car.getTotalTime() << endl;
             
        }
    // This line counter cars arriving
    // Consider enhancing to report specific cars
    cout << "Car " << carNumber++ << " arrived after closing time and was not served.\n";
    // End of simulation of car wash
    cout << "End of Simulation\n\n";
    cout << "Statistics:\n";    // Statistics
    cout << "   Total Wait Time: " << totalWait << " minutes\n";
    
    // Calculate average wait item in minutes and seconds
    int averageMin = servedCars > 0 ? totalWait / servedCars : 0;
    int averageSec = servedCars > 0 ? (totalWait * 60 / servedCars) % 60 : 0;
    cout << "   Average Wait Time: " << averageMin << " minutes and " << averageSec << " seconds\n";

    cout << "   Total car wash use time: " << totalCarWashUseTime << " minutes\n";

    // Calculate percentage of time car wash
    cout << fixed << setprecision(2);
    cout << "   Percentage of time car was was in use: " 
         << (totalCharge * 100.0 / SIMULATION_END_TIME) << "%\n";

    return 0; // Exit program
}
