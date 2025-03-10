#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>
#include <chrono>

using namespace std;

sem_t bin_sem;

void criticalSection(int id) {
    sem_wait(&bin_sem);
    cout << "Process " << id << " is in critical section\n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Process " << id << " is leaving critical section\n";
    sem_post(&bin_sem);
}

int main() {
    int n = 5;
    vector<thread> threads;
    
    sem_init(&bin_sem, 0, 1);

    for (int i = 0; i < n; i++)
        threads.push_back(thread(criticalSection, i + 1));

    for (auto &t : threads)
        t.join();

    sem_destroy(&bin_sem);
    return 0;
}
