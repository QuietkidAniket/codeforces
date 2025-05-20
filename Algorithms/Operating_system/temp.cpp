#include <iostream>
using namespace std;

const int P = 5; // Processes
const int R = 3; // Resources

bool isSafe(int processes[], int avail[], int max[][R], int allot[][R]) {
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];

    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) return false;
    }

    cout << "Safe sequence: ";
    for (int i = 0; i < P; i++)
        cout << "T" << safeSeq[i] << " ";
    cout << endl;
    return true;
}

bool requestResource(int processes[], int avail[], int max[][R], int allot[][R], int reqProcess, int request[]) {
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];

    for (int i = 0; i < R; i++) {
        if (request[i] > need[reqProcess][i]) return false;
        if (request[i] > avail[i]) return false;
    }

    for (int i = 0; i < R; i++) {
        avail[i] -= request[i];
        allot[reqProcess][i] += request[i];
        max[reqProcess][i] -= request[i];
    }

    if (isSafe(processes, avail, max, allot)) {
        return true;
    } else {
        for (int i = 0; i < R; i++) {
            avail[i] += request[i];
            allot[reqProcess][i] -= request[i];
            max[reqProcess][i] += request[i];
        }
        return false;
    }
}

int main() {
    int processes[P] = {0, 1, 2, 3, 4};
    int avail[R] = {3, 3, 2};

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int allot[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int request[R] = {1, 0, 2}; // T1 requesting

    if (requestResource(processes, avail, max, allot, 1, request))
        cout << "Request can be granted.\n";
    else
        cout << "Request cannot be granted.\n";

    return 0;
}
