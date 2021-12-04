#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    tm timerTime = {};
    //tm local = *localtime(&t);
    cout << "Set the time on the timer: [MM:SS]" << endl;
    cin >> get_time(&timerTime, "%M:%S");
    time_t currentTime = time(nullptr);
    time_t targetTime = currentTime + timerTime.tm_min * 60 + timerTime.tm_sec;

    // << timerTime.tm_min << ":" << timerTime.tm_sec << endl;

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
    // while (timerTime.tm_min > 0 || timerTime.tm_sec > 0)
    // {
    //     while (time(nullptr))
    //     cout << timerTime.tm_min << ":" << timerTime.tm_sec << endl; 
    //     timerTime.tm_sec--;
    //     if (timerTime.tm_sec == 0) {
    //         timerTime.tm_min--;
    //     }

    // }
    
}