#include<bits/stdc++.h>

using namespace std;

class Number {
  long _pn;char _type, _status; string _name;
  public:
  Number(long pn,char type,char status,string name):_pn(pn), _type(type), _status(status), _name(name){
    cout << _pn <<' '<< "constructed." <<endl;
  }
  Number(){}
  ~Number(){
    cout << _pn << ' ' << "destructed." << endl;
  }
  void say () {
    cout<< "Phone=" << _pn << "--"<<"Type=" << _type << "--" << "State=" << getstate() <<"--"<<"Owner="<< _name << endl ;
  }
  string getstate() {
    if(_status == '1') return "use";
    return "unuse";
  }
  friend int search(long x,Number* nu);
};

int search(long x,Number* nu){
  for(int i=0;i<3;i++){
    if(x == nu[i]._pn) return i;
  }
  return -1;
}

int main() {
    long pn[3];
    char type[3], status[3];
    string name[3];
  for(int i=0; i< 3; i++ ){
    cin >> pn[i] >> type[i] >> status[i] >> name[i];
  }
  Number nu[3] = {
    Number(pn[0],type[0],status[0],name[0]),
    Number(pn[1],type[1],status[1],name[1]),
    Number(pn[2],type[2],status[2],name[2])
  };
  int T;cin >>T;
  while(T--){
    long target;cin>>target;
    if(search(target,nu) == -1){
      cout<< "wrong number." <<endl;
    }
    else {
      nu[search(target,nu)].say();
    }
  }
}