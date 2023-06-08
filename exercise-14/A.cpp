#include<bits/stdc++.h>

using namespace std;

class myClock {
  int h,m,s;
  public:
  myClock(int h,int m, int s):h(h),m(m),s(s){}
  myClock() = default;
  void operator++ () {
    s += 1;
    init();
  }
  void operator-- () {
    s -= 1;
    if (s<0) {
      s=59;
      m -= 1;
    }
    if (m<0) {
      m=59;
      h -= 1;
    }
    if(h<0) {
      h=11;
    }
    init();
  }
  void init () {
      m += s/60;
      s = s%60;
      h += m/60;
      h %= 12;
      m %= 60;
  }
  void say() {
    cout << h << ':' << m << ':' << s << endl;
  }
};
int main () {
  int h,m,s; cin >> h >> m >> s;
  myClock a(h,m,s);
  int T;cin >> T;
  while(T--){
    int op; cin >> op;
    if(op>0){
      for(int i=0; i<op ;i++){
        ++a;
      }
    } else {
      for(int i=0; i<abs(op) ;i++) {
        --a;
      }
    }
    a.say();
  }
  return 0;
}

