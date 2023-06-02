#include<iostream>
#include<cstring>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setfill;
using std::setw;

class Time;
class Date{
    int y,m,d;
    public:
    Date();
    Date(int a,int b,int c):y(a),m(b),d(c){}
    friend void display(const Date&x,const Time& y);
};
class Time{
    int h,m,s;
    public:
    Time();
    Time(int a,int b ,int c):h(a),m(b),s(c){}
    friend void display(const Date&x,const Time& y);
};
void myprint(int a,int b){
    cout << setfill('0') << setw(a) << b;
}
void display(const Date&x,const Time& y){
    myprint(4,x.y);cout << '-';
    myprint(2,x.m);cout << '-';
    myprint(2,x.d);cout << ' ';
    myprint(2,y.h);cout << ':';
    myprint(2,y.m);cout << ':';
    myprint(2,y.s);cout << endl;
}

int main(){
    int n;cin >> n;
    while(n--){
        int x,y,z;
        cin >> x >> y >> z;
        Date da(x,y,z);
        cin >> x >> y >> z;
        Time ti(x,y,z);
        display(da,ti);

    }
}