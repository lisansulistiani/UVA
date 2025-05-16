#include<iostream>
#include<cmath>
#include<string>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  else return gcd(b, a%b);
}

using namespace std;
int main(){
  unsigned long long v1, d1, v2, d2;
  cin>>v1>>d1>>v2>>d2;
  int idx=1;
  while(v1 != 0 && d1 != 0 && v2 != 0 && d2 != 0){
    cout<<"Case #"<<idx<<": ";
    unsigned long long new_d1 = v2*d1;
    unsigned long long new_d2 = v1*d2;
    if (new_d2>new_d1){
      cout<<"You owe me a beer!"<<endl;
    }
    else{
      cout<<"No beer for the captain."<<endl;
    }
    unsigned long long numerator = new_d1 + new_d2;
    unsigned long long denominator = 2*v1*v2;
    unsigned long long divisor = gcd(numerator, denominator);
    numerator/=divisor;
    denominator/=divisor;

    cout << "Avg. arrival time: ";
    if (denominator == 1) {
        cout << numerator << endl;
    } else {
        cout << numerator << "/" << denominator << endl;
    }

    idx+=1;
    cin>>v1>>d1>>v2>>d2;
  }
  return 0;
}