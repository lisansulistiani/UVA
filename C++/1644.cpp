#include<iostream>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int prime(int k, bool upDown) {
    if (k <= 2) return 2;
    int n = k;
    while (!isPrime(n)) {
        if (upDown) n++;
        else n--;
        if (n < 2) return 2; // Avoid going below 2
    }
    return n;
}

int main(){
  // 0: down; 1: up
  int inp;
  cin>>inp;
  while(inp!=0){
    int bawah = prime(inp, false);
    int atas = prime(inp, true);
    cout<<atas-bawah<<endl;
    cin>>inp;
  }

  return 0;
}