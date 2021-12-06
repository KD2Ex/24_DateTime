#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

const time_t START = 0;
tm ERROR_TIME = *localtime(&START);

string getClosestDate(map<string, vector<string>> birthdays) {
    time_t t = time(nullptr);
    tm local = *localtime(&t);
    string closestDate = birthdays.begin()->first;
    int closestMonth = stoi(closestDate.substr(5, 2));
    int closestDay = stoi(closestDate.substr(8, 2));
    //vector<tm>();

    for (auto & i : birthdays) {
//        local.tm_hour;
//        i.first->tm_hour;
        int mapMonth = stoi(i.first.substr(5, 2));
        int mapDay = stoi(i.first.substr(8,2));
        if (mapMonth < local.tm_mon || (mapMonth == local.tm_mon && mapDay < local.tm_mday)) continue;

        int monthDiff = mapMonth - local.tm_mon;
        int dayDiff = mapDay - local.tm_mday;


    }
    if (&closestDate < &local) {
        time_t start = 0;
        return *localtime(&start);
    }
    return closestDate;
}

int main() {
    string name;
    string inputDate;
    map <string , vector<string>> birthdays;

    while (true) {
        cout << "Enter the data of birthday: [birthday boy name] [yyyy].[mm].[dd]\n";


        cin >> name >> inputDate;
        if (name == "end") break;

        if (birthdays.find(inputDate) == birthdays.end()) {
            birthdays.insert(make_pair(inputDate, vector<string>()));
            birthdays[inputDate].push_back(name);
        } else {
            birthdays[inputDate].push_back(name);
        }
    }
    tm closestDate = getClosestDate(birthdays);

    if (&closestDate == &ERROR_TIME) {
        cout << "Empty!" << endl;
        return 0;
    }

    for (auto & i : birthdays) {
        cout << closestDate.tm_mon << "/" << closestDate.tm_mday << " ";
        for (auto & j : i.second) {
            cout << j << ", ";
        }
        cout << endl;
    }
    cout << "Closest birthday will be on: " << closestDate.tm_mon << "/" << closestDate.tm_mday << endl;
    for (auto & i : birthdays[&closestDate]) {
        cout << i << endl;
    }
}
