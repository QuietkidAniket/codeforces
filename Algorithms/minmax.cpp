// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
#include<vector>
#include <ctime> 
#include <cstdlib> 
int main()
{
	int i,n, min,max,ele; int N = 100; 
    cout<< " Enter Vector size\n";
	vector<int> a;
	cin>>n;
	cout<<"Random elements between 0 to 99 ";

    // This program will create some sequence of random 
    // numbers on every program run within range 0 to N-1 
    for (int i = 0; i < n; i++) {
         ele= rand() % N ; 
		a.push_back(ele);
		cout<<a[i]<<"  ";
	}
	min = a[0];
	max = a[0];
	//  number of clock ticks elapsed since an epoch related to the particular program execution
	clock_t tStart = clock();
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
			min = a[i];
		if(a[i]>max)
			max = a[i];

	}
	//  number of clock ticks elapsed since an epoch related to the particular program execution
	// divide by CLOCKS_PER_SEC to get number of seconds taken
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	
	cout<<"\nTime taken is "<<time1<<endl;
	cout<<"Minimum is " <<min<<endl;
	cout<<"Max is "<<max<<endl;
}