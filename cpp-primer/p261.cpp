#include<bits/stdc++.h>

using namespace std;

/*
void readInput (istream& read) {
  string line;
  while (getline(read, line)) {
    cout << "You enterd"<< line << endl;
  }
}

int main () {
  readInput(cin);
  return 0;
}
*/

class myRead {
  string name ;
  public:
  // myRead(istream& c = cin){
  //   c >> name;
  // }
  myRead () {
    cin >> name;
  }
  void say () {
    cout << name ;
  }
};

int main () {
  myRead r;
  r.say();
}
