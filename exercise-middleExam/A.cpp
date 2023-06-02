#include<bits/stdc++.h>

using namespace std;

class Rebot{
  string _name;
  char _type;
  int _grade;
  int _blood, _defense, _harm;
  public:
  Rebot(string name,char type, int grade):_grade(grade),_type(type),_name(name) {
    setAttrs();
  }
  Rebot(){}
  void setAttrs () {
    _blood = 5 * _grade; _defense = 5*_grade; _harm = 5* _grade;
    switch (_type) {
      case 'N': break;
      case 'A': _blood = 5 * _grade; _defense = 5*_grade; _harm = 10 * _grade; break;
      case 'D': _blood = 5 * _grade; _defense = 10 *_grade; _harm = 5* _grade; break;
      case 'H': _blood = 50 * _grade; _defense = 5*_grade; _harm = 5* _grade; break;
    }
  }
  void say () {
    cout << _name <<"--"<< _type << "--"<< _grade<<"--"<<_blood<<"--"<<_harm<<"--"<<_defense<<endl;
  }
  bool toOther(char a){
    if (a == _type) return false;
    _type = a;
    setAttrs();
    return true;
  }
};

int main() {
  int T;cin >> T;int cnt =0;
  while(T--){
    string a;char b,c;int d;
    cin >> a >> b >>d >>c;
    Rebot re(a,b,d);
    if(re.toOther(c)) cnt++;
    re.say();
  }
  cout << "The number of robot transform is " << cnt;
}