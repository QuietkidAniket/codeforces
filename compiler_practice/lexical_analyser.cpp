#include <bits/stdc++.h>
using namespace std;


unordered_set<string> st = {
    "auto","break","case","char","const","continue","default","do","double","else",
    "enum","extern","float","for","goto","if","int","long","register","return","short",
    "signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
    "volatile","while", "int"
};

bool is_keyword(const string& s){
  return st.find(s) != st.end();
}

bool is_identifier(const string& s){
  if(!isalpha(s[0]) && s[0] != '_')return false;
  for(int i = 1 ;i < s.size(); i++){
    if(!isalnum(s[i]) && s[0] != '_')return false;
  }
  return (st.find(s) == st.end());
}



void parse(const string& filename){
  ifstream fp(filename);

  if(!fp.is_open()){
    perror("Error!");
  }

  vector<string> input;
  string x;
  while((fp>>x)){
    input.push_back(x);
  }

  vector<string> identifiers;
  vector<string> keywords;
  bool flag = false;
  bool comment = false;
  bool str = false;
  for(string& token: input){
    if(token.back() == ';')token.pop_back();
    // if comment ignore
    if(token[0] == '/'){

      // single line
      if(token.size() > 1 && token[1] == '/')continue;
      else flag = true;
    }
    if(flag){
      if(token[0] == '*'){
        comment = true;
        continue;
      }else flag = false;
    }
    if(comment){
      if(token.find('/') != string::npos){
        comment = false;
        flag = false;
        continue;
      }else continue;
    }

    // check if string 
    if(!str && (token.find('"') != string::npos || token.find('\'') != string::npos)){
      str = true;
      continue;
    }
    if(str && (token.find('"') != string::npos || token.find('\'') != string::npos)){
      str = false;
      continue;
    }


    // otherwise 
    if(is_identifier(token))identifiers.push_back(token);
    if(is_keyword(token))keywords.push_back(token);
  }
  cout << " identifiers : \n"; 
  for(auto& x : identifiers)cout << x << " ";
  cout << " \nkeywords : \n"; 
  for(auto& x : keywords)cout << x << " ";
}



int main(){
  string filename;
  cin>> filename;

  parse(filename);
  return 0;
}