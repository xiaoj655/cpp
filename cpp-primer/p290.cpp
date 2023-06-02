#include<bits/stdc++.h>

using namespace std;

class a {
  int& c;
  public:
  // a(int x){
  //   c = x;
  // }
  a(int x):c(x){}
};
int main(){
  int c; cin >> c;
  a aa(c);
}