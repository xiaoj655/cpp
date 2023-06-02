#include<bits/stdc++.h>

using namespace std;

class Account {
  long _id;
  double _balance;
  double _rate;
  char _type;
  public:
  Account(){}
  Account(long id, int balance, char type):_id(id), _balance(balance), _type(type),_rate(0.005){}
  Account(Account& other){
    _id = other._id + 50000000;
    _rate = 0.015;
    _balance = other._balance;
  }
  void sumInterest () {
    _balance *= (1+_rate);
    cout << "Account=" <<_id << "--sum=" << _balance<<endl;
  }
  void say () {
    cout << "Account=" <<_id << "--" << getType() << "--sum=" << _balance << "--rate=" << _rate << endl;
  }
  string getType () {
    if(_type == 'E') return "Enterprise";
    return "Person";
  }
};

int main () {
  int T;cin >> T;
  while (T--) {
    long id;char type;int balance;
    cin >> id >> type >> balance ;
    Account a(id,balance,type);
    Account b(a);
    char x;cin >> x;
    if (x == 'C') {
      a.sumInterest();
    } else {
      a.say();
    }
    cin >> x;
    if(x == 'C'){
      b.sumInterest();
    } else {
      b.say();
    }
  }
  return 0;
}