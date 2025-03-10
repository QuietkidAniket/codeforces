#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, arrival, burst, priority, waiting, turnaround, completion;
};

void calculateTimes(vector<Process>& data) {
    int n = data.size(), currentTime = 0;
    vector<bool> completed(n, false);
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && data[i].arrival <= currentTime) {
                if (idx == -1 || data[i].priority < data[idx].priority || 
                   (data[i].priority == data[idx].priority && data[i].arrival < data[idx].arrival)) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            currentTime = max(currentTime, data[idx].arrival) + data[idx].burst;
            data[idx].completion = currentTime;
            data[idx].turnaround = data[idx].completion - data[idx].arrival;
            data[idx].waiting = data[idx].turnaround - data[idx].burst;
            completed[idx] = true;
            ++completedProcesses;
        } else {
            ++currentTime;
        }
    }
}

void printResults(const vector<Process>& data) {
    double totalWaiting = 0, totalTurnaround = 0;
    cout << "\nID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n";
    for (const auto& p : data) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\t\t" << p.waiting << "\t" << p.turnaround << "\n";
        totalWaiting += p.waiting;
        totalTurnaround += p.turnaround;
    }
    cout << "\nAverage Waiting Time: " << totalWaiting / data.size();
    cout << "\nAverage Turnaround Time: " << totalTurnaround / data.size() << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> data(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> data[i].arrival >> data[i].burst >> data[i].priority;
        data[i].id = i + 1;
    }

    calculateTimes(data);
    printResults(data);

    return 0;
}
