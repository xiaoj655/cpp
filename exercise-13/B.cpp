#include<bits/stdc++.h>

using namespace std;
class Group {
  public:
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
};
class GroupA : Group{
  public:
  GroupA() = default ;
  int add(int x, int y){
    return x+y;
  }
  int sub(int x, int y){
    return x-y;
  }
};
int f(int i){
  int res=1;
  for(int a=0;a<i;a++){
    res *= 10;
  }
  return res;
}
class GroupB : Group {
  public:
  GroupB() = default ;
  int add(int x , int y) {
    return x+y;
  }
  int sub(int x, int y) {
    int res = x-y;
    for(int i=0;;i++){
      if(x == 0 || y==0) break;
      int temx = x%10,temy = y%10;
      temx -= temy;
      if(temx < 0) res += 10*f(i);
      x /= 10;y/=10;
    }
    return res;
  }
};

class GroupC : Group {
  public:
  GroupC() = default ;
  int add (int x, int y){
    int res = 0;
    for(int i=0;;i++){
      if(x == 0 && y == 0) break;
      int temx = x%10,temy = y%10;
      temx += temy;
      if(temx >= 10) temx -= 10;
      res += temx * f(i);
      x /= 10;y/=10;
    }
    return res;
  }
  int sub(int x, int y) {
    int res = x-y;
    for(int i=0;;i++){
      if(x == 0 || y==0) break;
      int temx = x%10,temy = y%10;
      temx -= temy;
      if(temx < 0) res += 10*f(i);
      x /= 10;y/=10;
    }
    return res;
  }
};
int main(){
  int T;cin >> T;
  while (T--) {
    int t,x,y;char o;
    cin >> t >> x >> o >>y;
    switch (t)
    {
    case 1:
      if(o == '+'){
        cout << GroupA().add(x,y) << endl;
      } else {
        cout << GroupA().sub(x,y) << endl;
      }
      break;
    case 2:
      if(o == '+'){
        cout << GroupB().add(x,y) << endl;
      } else {
        cout << GroupB().sub(x,y) << endl;
      }
      break;
    default:
      if(o == '+'){
        cout << GroupC().add(x,y) << endl;
      }else {
        cout << GroupC().sub(x,y) << endl;
      }
    }
  }
}