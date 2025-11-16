#include <bits/stdc++.h>
using namespace std;

map<string, vector<vector<string>> > productions;
map<string, vector<string>> first, follow;
set<string> terminals;

set<string>  get_first_string(const vector<string>& alpha){
  set<string> res;
  for(const auto& B : alpha){
    for(const auto& x : first[B]){
      if(x == "epsilon")continue;
      res.insert(x);
    }

    if(first[B].count("epsilon") == 0){
      return res;
    }
  }
  res.push("epsilon");
  return res;

}


void compute_first(){
  bool changed = false;
  while(!changed){
    set<string> res;
    for(const auto& prod : productions[A]){

      for(const auto& B : prod){
        if(B == "epsilon")continue;
        if(res.find(B) == res.end()){
          res.push(B);
        }
      }

      if(prod.count("epsilon") == 0){
        return res;
      }
    }
  }
}

void compute_follow(){

}




void Solve(){

}



int32_t main(){

  // parse the grammer provided 
  // store it in productions
  solve();

  return 0;
}