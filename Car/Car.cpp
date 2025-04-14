/********************************************
 * Car Wash Simulation Program
 * Simulates a single-car wash based on arrival times
 * Author: Your Name
 * Version: Due Date
 *********************************************/

 #include <iostream>
 #include <fstream>
 #include <queue>
 #include <vector>
 #include <iomanip>
 
 using namespace std;
 
 // Constants
 const int SIMULATION_END_TIME = 540; // 9 hours = 540 minutes
 const int CAR_WASH_DURATION = 3;     // 3 minutes per car
 
 // Car struct
 struct Car {
     int carNumber;
     int arrivalTime;
     int startTime;
     int departureTime;
     int waitTime;
     int totalTime;
 };
 
 int main() {
     ifstream infile("arrival_time.txt");
     if (!infile) {
         cerr << "Error opening file.\n";
         return 1;
     }
 
     queue<int> arrivals;
     int time;
     while (infile >> time) {
         arrivals.push(time);
     }
 
     vector<Car> cars;
     vector<pair<int, int>> rejectedCars; // <carNumber, arrivalTime>
     int currentTime = 0;
     int carNumber = 1;
     int totalWaitTime = 0;
 
     // Simulation start
     cout << "Opening Time: 8:00 AM (0 minutes)\n";
     cout << "Closing Time: 5:00 PM (540 minutes)\n";
     cout << "Start of Simulation\n\n";
 
     cout << left << setw(12) << "Car Number" << setw(15) << "Arrival Time"
          << setw(20) << "Car Wash Start" << setw(15) << "Departure"
          << setw(12) << "Wait Time" << setw(12) << "Total Time" << endl;
 
     while (!arrivals.empty()) {
         int arrival = arrivals.front();
         arrivals.pop();
 
         if (arrival > SIMULATION_END_TIME) {
             rejectedCars.push_back({carNumber, arrival});
             carNumber++;
             continue;
         }
 
         Car car;
         car.carNumber = carNumber;
         car.arrivalTime = arrival;
         car.startTime = max(currentTime, arrival);
         car.departureTime = car.startTime + CAR_WASH_DURATION;
         car.waitTime = car.startTime - arrival;
         car.totalTime = car.departureTime - arrival;
 
         cars.push_back(car);
         totalWaitTime += car.waitTime;
         currentTime = car.departureTime;
 
         // Output info for this car
         cout << left << setw(12) << car.carNumber
              << setw(15) << car.arrivalTime
              << setw(20) << car.startTime
              << setw(15) << car.departureTime
              << setw(12) << car.waitTime
              << setw(12) << car.totalTime << endl;
 
         carNumber++;
     }
 
     // Handle rejected cars
     for (auto& p : rejectedCars) {
         cout << "Car " << p.first << " arrived at " << p.second
              << " minutes and was not served (arrived after closing time).\n";
     }
 
     // Statistics
     int totalCars = cars.size();
     int totalUseTime = totalCars * CAR_WASH_DURATION;
     double averageWait = totalCars > 0 ? static_cast<double>(totalWaitTime) / totalCars : 0;
     int avgMin = static_cast<int>(averageWait);
     int avgSec = static_cast<int>((averageWait - avgMin) * 60);
     double usagePercent = (static_cast<double>(totalUseTime) / SIMULATION_END_TIME) * 100;
 
     cout << "\nEnd of Simulation\n\n";
     cout << "Statistics:\n";
     cout << "Total wait time: " << totalWaitTime << " minutes\n";
     cout << "Average wait time: " << avgMin << " minutes and " << avgSec << " seconds\n";
     cout << "Total car wash use time: " << totalUseTime << " minutes\n";
     cout << fixed << setprecision(2);
     cout << "Percentage of time car wash was in use: " << usagePercent << "%\n";
 
     return 0;
 }
 