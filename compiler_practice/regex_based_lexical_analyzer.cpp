#include <bits/stdc++.h>
using namespace std;

static vector<string> keywords = {
  "if", "else", "while", "return", "int", "float", "double",
  "char", "for", "break", "continue", "void"
};

bool is_keyword(string& s){
  return (keywords.find(s) != keywords.end());
}

int32_t main(){
  string filename;
  cin>> filename;

  ifstream fp(filename);
  string s = "", line;
  while(getline(fp, line)){
    s += line + "\n";
  }

  // replace all single line comments
  s = regex_replace(s, regex_search("//.*"), ""); 
  // replace all multi-line comments
  s = regex_replace(s, regex_search("/\\*.*?\\*/", regex::dotall), "");


  regex token("");

  regex identifier("[A-Za-z][A-Za-z0-9_]*");
  regex integer("\\d+.*");
  regex floating("\\d+\\.\\d+");
  regex Operator("<=|=>|==|!=|[+\\-*/=<>]");
  regex special_symbol("[(){};,]");

  
  regex string_literal("\"([^\"\\\\]|\\\\.)*\"");

  smatch m;
  while(regex_search(s,m, token)){  
    string t = m.str();

    if(regex_match(m, identifier)){

    }
    else if(regex_match(m, integer)){

    }
    else if(regex_match(m, floating)){

    }
    else if(regex_match(m, Operator)){

    }
    else if(regex_match(m, special_symbol)){

    }else{

    }
    s = m.suffix();

  }

  return 0;
}