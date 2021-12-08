#include <iostream>
#include <ctime>
#include <map>
#include <vector>
using namespace std;

struct ClosedTask {
    string name;
    time_t timeSpent;
};

enum Commands {
   BEGIN = 1,
   END,
   STATUS,
   EXIT,
};

string getTime(time_t timeSpent) {
    int days = timeSpent / 86400;
    int hours = timeSpent / 3600 % 24;
    int minutes = (timeSpent % 3600) / 60;
    int seconds = timeSpent % 60;


    return to_string(days) + " days " + to_string((hours / 10)) + to_string(hours % 10)
        + ":" + to_string((minutes / 10)) + to_string(minutes % 10)
        + ":" + to_string((seconds / 10)) + to_string(seconds % 10);
}

ClosedTask closeTask(string& currentTaskName, time_t& t) {
    time_t timeSpent = (time_t)difftime(time(nullptr), t);
    t = 0;

    cout << currentTaskName << " is over. Time spent: "
         << getTime(timeSpent) << endl;

    string taskName = currentTaskName;
    currentTaskName = "";

    ClosedTask closedTask;
    closedTask.name = taskName;
    closedTask.timeSpent = timeSpent;

    return closedTask;
}

int main() {
    map <string, int> commands;
    commands["begin"] = BEGIN;
    commands["end"] = END;
    commands["status"] = STATUS;
    commands["exit"] = EXIT;

    vector<ClosedTask> closedTasks;
    string inputCommand;
    string currentTaskName;
    time_t t = 0;


    while (true) {
        cout << "Enter the command: [begin|end|status|exit]\n";
        cin >> inputCommand;
        switch (commands[inputCommand]) {
            case BEGIN: {
                if (!currentTaskName.empty()) {
                    closedTasks.push_back(closeTask(currentTaskName, t));
                }
                cout << "Enter the name of a new task:\n";
                cin >> currentTaskName;
                t = time(nullptr);
            }
                break;
            case END: {
                if (!currentTaskName.empty()) {
                    closedTasks.push_back(closeTask(currentTaskName, t));
                }
                break;
            }
            case STATUS:
                if(!closedTasks.empty()) {
                    cout << "Closed tasks:\n";
                    for (auto & i : closedTasks) {
                        cout << "Task: " << i.name << ". time spent: " << getTime(i.timeSpent) << endl;
                    }
                }
                if (!currentTaskName.empty()) cout << endl << "Current task is " << currentTaskName << endl;
                break;
            case EXIT:
                return 0;
            default:
                cout << "Wrong command!" << endl;
                break;
        }
    }
}
