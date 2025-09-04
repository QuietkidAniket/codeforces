/**
 *    author: Anicetus_7
 *    created: 2025-09-02 10:44:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long

void Solve(){
  int n; cin>>n;
  string s; cin>>s;
  umap<char,int> mp;
  for(int i = 0; i< n; i++)
  {
   mp[s[i]]++;
  }
  // find best k <- number of distinct characters
  int bestk = n, mnops =n;
  for(int k=1;k <=n; k++){
    if(n%k == 0){
      int reqf = n/k;
      int less =0;
      int more = 0;
      for(const auto& [c, f] : mp){
        if(reqf > f){
          int inc = reqf-f;
          less+= inc;
        }
        if(reqf < f){
          more += f-reqf;
        }
      }
      if(more < less){
        less = more + (less-more)/k;
      }else{
        less = more;
      } 

      if(less < mnops){
        mnops = less;
        bestk = k;
      }
    }
  }
  cout << bestk << endl;
  
  string res =s;
  vector<char> less;
  int more =0;
  int reqf = n/bestk;
  for(const auto& [c, f] : mp){
    if(reqf > f){
      int inc = reqf-f;
      while(inc--)less.push_back(c);
    }
    if(reqf < f)more+= f- reqf;
  }
  char newc = ' ';
  for(char c='a';c <= 'z';c++){
    if(mp[c]==0){
      newc = c;
      break;
    } 
  }
  umap<char,int> mp2;
  for(int i =0;i <n; i++){
    if(reqf < mp[s[i]]){
      // add more less elements by replacing more elements
      if(!less.empty()){
        res[i]= less.back();
        less.pop_back();
      }else{ // add more less elements by introducing new element
        res[i] = newc;
      }
    }
    mp2[res[i]]++;
    mp[s[i]]--;
  }

  // still less elements left (in case more less elements than more elements)
  // then duplicate the most frequent - less elements to match the n/k count;
  if(!less.empty()){
    vector<pair<int,char>> vec;
    int total_slots= 0;
    for(const auto& [c, f]: mp2){
      if(reqf > f){
        vec.push_back({f,c});
        total_slots += f;
      }
    }

    sort(vec.rbegin(), vec.rend());

    // each need to be exactly reqf
    int nrequired = total_slots/reqf;

    unordered_map<char,int> replacer;
    vector<int> r;
    for(int i = 0; i < nrequired; i++){
      replacer[vec[i].second] = reqf;
      r.push_back(vec[i].second);
    } 


    int ptr =0;
    for(int i =0 ;i <n; i++){
      if(mp2[res[i]] < reqf && replacer[res[i]]==0){
        char elem = r[ptr];
        res[i] = elem;
        if(--replacer[elem] == 0){replacer.erase(elem);ptr++;}
      }
    }
  }




  cout << res << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}