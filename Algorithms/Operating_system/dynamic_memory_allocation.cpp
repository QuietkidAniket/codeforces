#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Function to perform First-fit allocation
void firstFit(vector<int> &memoryPartitions, vector<int> &processes)
{
  vector<int> allocation(processes.size(), -1); // -1 indicates not allocated
  for (int i = 0; i < processes.size(); i++)
  {
    for (int j = 0; j < memoryPartitions.size(); j++)
    {
      if (memoryPartitions[j] >= processes[i])
      {
        allocation[i] = j;
        memoryPartitions[j] -= processes[i];
        break;
      }
    }
  }
  cout << "First-fit Allocation:" << endl;
  for (int i = 0; i < allocation.size(); i++)
  {
    if (allocation[i] != -1)
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is allocated to partition "
           << allocation[i] + 1 << endl;
    else
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is not allocated." << endl;
  }
}
// Function to perform Best-fit allocation
void bestFit(vector<int> &memoryPartitions, vector<int> &processes)
{
  vector<int> allocation(processes.size(), -1);
  for (int i = 0; i < processes.size(); i++)
  {
    int bestIdx = -1;
    int minDiff = INT_MAX;
    for (int j = 0; j < memoryPartitions.size(); j++)
    {
      if (memoryPartitions[j] >= processes[i] && memoryPartitions[j] - processes[i] < minDiff)
      {
        bestIdx = j;
        minDiff = memoryPartitions[j] - processes[i];
      }
    }
    if (bestIdx != -1)
    {
      allocation[i] = bestIdx;
      memoryPartitions[bestIdx] -= processes[i];
    }
  }
  cout << "Best-fit Allocation:" << endl;
  for (int i = 0; i < allocation.size(); i++)
  {
    if (allocation[i] != -1)
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is allocated to partition "
           << allocation[i] + 1 << endl;
    else
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is not allocated." << endl;
  }
}
// Function to perform Worst-fit allocation
void worstFit(vector<int> &memoryPartitions, vector<int> &processes)
{
  vector<int> allocation(processes.size(), -1);
  for (int i = 0; i < processes.size(); i++)
  {
    int worstIdx = -1;
    int maxDiff = -1;
    for (int j = 0; j < memoryPartitions.size(); j++)
    {
      if (memoryPartitions[j] >= processes[i] && memoryPartitions[j] - processes[i] > maxDiff)
      {
        worstIdx = j;
        maxDiff = memoryPartitions[j] - processes[i];
      }
    }
    if (worstIdx != -1)
    {
      allocation[i] = worstIdx;
      memoryPartitions[worstIdx] -= processes[i];
    }
  }
  cout << "Worst-fit Allocation:" << endl;
  for (int i = 0; i < allocation.size(); i++)
  {
    if (allocation[i] != -1)
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is allocated to partition "
           << allocation[i] + 1 << endl;
    else
      cout << "Process " << i + 1 << " of size " << processes[i] << " MB is not allocated." << endl;
  }
}
int main()
{
  // Memory partitions (in MB)
  vector<int> memoryPartitions = {100, 170, 40, 205, 300, 185};
  // Processes to be allocated (in MB)
  vector<int> processes = {200, 15, 185, 75, 175, 80};
  // First-fit allocation
  vector<int> memoryPartitionsFirstFit = memoryPartitions;
  firstFit(memoryPartitionsFirstFit, processes);
  cout << endl;
  // Best-fit allocation
  vector<int> memoryPartitionsBestFit = memoryPartitions;
  bestFit(memoryPartitionsBestFit, processes);
  cout << endl;
  // Worst-fit allocation}
  vector<int> memoryPartitionsWorstFit = memoryPartitions;
  worstFit(memoryPartitionsWorstFit, processes);
  return 0;
}
