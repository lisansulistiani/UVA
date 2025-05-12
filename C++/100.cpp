#include<iostream>
#include<algorithm>
using namespace std;


int three_n_plus_one(long long int n, long long int sizes ) {//{std::vector<int>& dynamicArray){
  if (n==1){
    return sizes;
  }
  else{
    sizes += 1;
    if (n%2!=0){
      return three_n_plus_one((3*n)+1, sizes);
    }
    else{
      return three_n_plus_one(n/2, sizes);
    }
  }
}

int main(){
  int i, j;
  while(cin >> i >> j){
    long long int sizes, maxs;
    maxs = -1;
    for (int k= min(i,j); k <= max(i,j); k++){
      sizes = three_n_plus_one(k, 1);
      if (sizes>maxs){
        maxs = sizes;
      }
    }
    cout<<i<<" "<<j<<" "<<maxs<<endl;
  }
  return 0;
}