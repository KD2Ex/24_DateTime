#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    tm timerTime = {};
    
    cout << "Set the time on the timer: [MM:SS]" << endl;
    cin >> get_time(&timerTime, "%M:%S");
    time_t currentTime = time(nullptr);
    time_t targetTime = currentTime + timerTime.tm_min * 60 + timerTime.tm_sec;

    while (currentTime != targetTime) {
        time_t diff = targetTime - currentTime;
        currentTime = time(nullptr);
        if (currentTime + diff != targetTime) {
            int newDiff = targetTime - currentTime;
            int minutes = newDiff / 60;
            int seconds = newDiff % 60; 
            cout << minutes << ":" << seconds / 10 << seconds % 10 << endl;
        }
    }

    cout << "Ding!" << endl;
}