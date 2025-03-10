#include <bits/stdc++.h>
using namespace std;

inline bool custom_compare(const pair<int,int> a, const pair<int,int> b){
    // compares based on ending time
    if(a.second == b.second)return a.first < b.first;
    return a.second < b.second;
}


void solve(){
    /*
    There are N events, each described by their starting and ending times. You can
    only attend one event at a time, and if you choose to attend an event, you must
    attend the entire event. Traveling between events is instantaneous. What's the
    maximum number of events you can attend?
    */   

    // no of events
    int n;
    cin>> n;

    // schedule of all events, starting_time: ending_time pair
    vector<pair<int,int>> schedule(n); 
    for(int i = 0; i< n; i++)
    {   
        cin >> schedule[i].first >> schedule[i].second;
    }

    sort(schedule.begin(), schedule.end(), custom_compare);

    // for(int i = 0; i< n; i++)
    // {
    //     cout << schedule[i].first << " : "  <<schedule[i].second <<  ", "; 
    // }
    // cout << '\n';

    // good greedy search for the maximum number of events which we can register out of all the events
    int currEventEnd =-1;
    int ans = 0;

    for(int i = 0; i< n; i++)
    {
        if(schedule[i].first >= currEventEnd){ // if the event can be attended (start time should be more than the ending time of the prev event)
            // we are attending the next event
            currEventEnd = schedule[i].second;
            ans++;
        }   
    }
    cout << ans << " : the maximum number of events which we can register out of all the events" << '\n';

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    solve();
    
    
    return 0;
}