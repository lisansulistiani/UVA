#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
  string inp;
  while (getline(cin, inp)){
    string words = "";
    for (char& c : inp){
      if (c!=' '){
        words += c;
      }
      else{
        reverse(words.begin(), words.end());
        words+=' ';
        cout<<words;
        words = "";
      }
    }
    if (words!=""){
      reverse(words.begin(), words.end());
      cout<<words;
    }
    cout<<endl;
  }
  return 0;
}