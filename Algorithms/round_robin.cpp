#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int id, arrival, burst, remaining, waiting, turnaround, completion;
};

void calculateTimes(vector<Process>& data, int timeQuantum) {
    int n = data.size(), currentTime = 0, completedProcesses = 0;
    queue<int> q;
    vector<bool> inQueue(n, false);

    auto arrivalCmp = [](Process a, Process b) { return a.arrival < b.arrival; };
    sort(data.begin(), data.end(), arrivalCmp);

    q.push(0);
    inQueue[0] = true;

    while (completedProcesses < n) {
        int idx = q.front();
        q.pop();

        if (data[idx].remaining <= timeQuantum) {
            currentTime = max(currentTime, data[idx].arrival) + data[idx].remaining;
            data[idx].remaining = 0;
            data[idx].completion = currentTime;
            data[idx].turnaround = data[idx].completion - data[idx].arrival;
            data[idx].waiting = data[idx].turnaround - data[idx].burst;
            completedProcesses++;
        } else {
            currentTime = max(currentTime, data[idx].arrival) + timeQuantum;
            data[idx].remaining -= timeQuantum;
        }

        for (int i = 0; i < n; ++i) {
            if (!inQueue[i] && data[i].arrival <= currentTime && data[i].remaining > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (data[idx].remaining > 0) q.push(idx);
    }
}

void printResults(const vector<Process>& data) {
    double totalWaiting = 0, totalTurnaround = 0;
    cout << "\nID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto& p : data) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.waiting << "\t" << p.turnaround << "\n";
        totalWaiting += p.waiting;
        totalTurnaround += p.turnaround;
    }
    cout << "\nAverage Waiting Time: " << totalWaiting / data.size();
    cout << "\nAverage Turnaround Time: " << totalTurnaround / data.size() << "\n";
}

int main() {
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> data(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> data[i].arrival >> data[i].burst;
        data[i].id = i + 1;
        data[i].remaining = data[i].burst;
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    calculateTimes(data, timeQuantum);
    printResults(data);

    return 0;
}
