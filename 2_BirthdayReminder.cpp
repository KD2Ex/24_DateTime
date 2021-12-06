#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

struct PersonBirthday {
    string name;
    tm date;
};

int getDaysInDate(tm &date) {
    int count = 0;

    for (int i = 0; i < date.tm_mon; i++) {
        switch (i) {
        case 1:
            count += 28;
            break;
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11:
            count += 31;
            break;
        case 3:
        case 5:
        case 8:
        case 10:
            count += 30;
            break;
        default:
            break;
        }
    }

    return count;
}

tm getNearestDate(vector<PersonBirthday> calendar) {
    tm nearestDate = calendar[0].date;
    time_t t = time(nullptr);
    tm local = *localtime(&t);
    vector<PersonBirthday> nearestBirthdays;
    
    for (auto & i : calendar) {
        int diff = getDaysInDate(i.date) - getDaysInDate(local);
        int minDiff = getDaysInDate(i.date) - getDaysInDate(nearestDate);
        if (diff < 0) continue;
        if (diff < minDiff) {
            minDiff = diff;
            nearestDate = i.date;
        }
    }
    return nearestDate;
}

int main() {
    string name;
    string inputDate;
    vector<PersonBirthday> calendar;

    while (true) {
        PersonBirthday person;
        time_t t = time(nullptr);
        tm local = *localtime(&t);
        
        person.date = local;

        cout << "Enter the name:\n";
        cin >> name;
        if (name == "end") break;

        cout << "Enter the birthday: [YYYY/MM/DD]\n";

        cin >> get_time(&person.date, "%Y/%m/%d");
        person.name = name;
        
        calendar.push_back(person);
    }

    tm nearestDate = getNearestDate(calendar);
    
    cout << "Nearest birthday is: " << 
        (nearestDate.tm_mon + 1) / 10 << (nearestDate.tm_mon + 1) % 10 << 
        "/" << 
        nearestDate.tm_mday / 10 << nearestDate.tm_mday % 10 << endl;
    for (auto & i : calendar) {
        if (i.date.tm_mon == nearestDate.tm_mon && 
            i.date.tm_mday == nearestDate.tm_mday) {
                cout << i.name << endl;
        }
    }
}
