#include<bits/stdc++.h>

using namespace std;

int main(){
  double average = 15.6784;
  int n = 10;
  double res = 0;
  while(n--){
    double r; cin >> r;
    res += pow(15+r/1000-average,2);
  }
  cout << res << '|' << res/90;
}