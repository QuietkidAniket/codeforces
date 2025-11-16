/**
 *    author: Anicetus_7
 *    created: 2025-09-27 08:57:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  string s; cin>>s;

  int cnt= 0;
  vector<int> freq(26,0);

  for(int i = 0; i <n; i++){
    freq[s[i]-'a']++;
  }
  
  vector<pair<int,char>> ch;
  for(int i = 0; i < 26; i++){
    if(freq[i] == 0)continue;
    cnt++;
    ch.push_back({freq[i], i+'a'});
  }
  sort(ch.rbegin(), ch.rend());
  
  string ans = s;
  int bestk = -1;
  int mnchanges = n;

  for(int k = 1; k <= min(n,26ll); k++){
    if(n%k != 0)continue; 
      
    if(k <= cnt){
      int changes = 0;
      for(int i = 0; i < k; i++){
        auto& [f,c] = ch[i];
        if(f >= n/k)continue;
        changes += n/k - f;
      }
      if(changes < mnchanges){
        mnchanges = changes;
        bestk = k;
      }
    }else{  
      int changes = 0;
      
      for(int i = 0; i < cnt; i++){ 
        auto& [f,c] = ch[i];
        if(f >= n/k)continue;
        changes += n/k - f;
      }
      // add new elems
      int added =0;
      for(char c= 'a'; c <='z' && added < k-cnt; c++){
        if(freq[c-'a'] != 0)continue;
        changes += n/k;
        added++;
      }
      if(changes < mnchanges){
        mnchanges = changes;
        bestk = k;
      }
    }
  }

  cout << mnchanges << endl;
  int k =bestk;

  // choosing the candidates
  vector<char> cand;
  if(k <= cnt){
    for(int i = 0; i<k ; i++)cand.push_back(ch[i].second);
  }else{
    for(int i = 0; i<cnt; i++)cand.push_back(ch[i].second);
      for(char c = 'a' ; c <='z' && cand.size() < k; c++)if(freq[c-'a'] == 0)cand.push_back(c);
  }


  // we need n/k candidates each
  vector<int> need(26, 0);
  for(char c: cand)need[c-'a']= n/k;

  // first pass: we note the excess candidates' indices
  // excess candidates' indices become our replacement indices
  vector<int> replacements;
  for(int i = 0;i <n ; i++){
    char c = s[i];
    if(need[c-'a'] > 0){
      need[c-'a']--;
    }else replacements.push_back(i);
  }

  // replacement indices are now given the characters one by one
  string t =s;
  int p = 0;
  for (int idx : replacements) {  
    while(need[p] == 0)p++;
    t[idx] = p + 'a';
    need[p]--;
  }
  cout << t<<endl;
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