/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
	int n,m,k; cin>>n>>m>>k;
	vector<int> a(n), b(m);
	for(auto& x : a)cin>>x;
	for(auto& x : b)cin>>x;
	sort(b.begin(), b.end());
	
	vector<pair<int,int>> left(n), right(n);
	for(int i =0 ;i <n; i++){
	    int r  =  upper_bound(b.begin(), b.end(), a[i])-b.begin();
	    int l  =  r-1;
		if(r == m){
    		left[i] = {a[i]-b[l], i};
    		right[i] = {INF,i};
		}else if(l == -1){
    		left[i] = {INF,i};
    		right[i] = {b[r]-a[i],i};
		}else{
    		left[i] = {a[i]-b[l],i};
    		right[i] = {b[r]-a[i],i};
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	
	string s; cin>>s;
	assert((int)s.size() == k);
	int pos = 0, lptr =0, rptr=0;
	
	unordered_set<int> st;
	for(int i =0  ;i < k; i++){
	    if(s[i] == 'R')pos++;
		else pos--;
		if(pos < 0){
		    int nlptr = upper_bound(left.begin()+lptr, left.end(), make_pair(-pos, INF))-left.begin();
			while(lptr< nlptr){
			    st.insert(left[lptr++].second);
			}
		}else if(pos > 0){
		    int nrptr = upper_bound(right.begin()+rptr, right.end(),make_pair(pos, INF))-right.begin();
			while(rptr< nrptr){
			    st.insert(right[rptr++].second);
			}
		}
		cout << n-st.size() << " ";	
	}
	cout << endl;
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