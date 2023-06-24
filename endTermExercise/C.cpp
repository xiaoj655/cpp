#include<bits/stdc++.h>

using namespace std;


int cal_gap_day (int y1,int m1,int d1,int y2,int m2, int d2) {
    int gap=0;
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=y1;i<y2;i++) {
        if( i%4==0 && i%100!=0 || i%400 ==0) gap +=366;
        else gap += 365;
    }
    if(y2%4==0 && y2%100!=0 || y2%400 ==0) month[2] = 29;
    for(int i=1;i<m2;i++) gap += month[i];
    for(int i=1;i<m1;i++) gap -= month[i];
    gap += d2;
    gap -= d1;
    return gap;
}


class CDate {
    int year,month,day;
    public:
    CDate (int year,int month,int day):year(year),\
    month(month),day(day){}
    CDate (const CDate& date):year(date.year),\
    month(date.month),day(date.day){}
    friend int cal_gap_day (int y1,int m1,int d1,int y2,int m2, int d2);
    friend class Cat;
    friend class Dog;
};
class Pet {
    protected:
    string name ;
    float length;
    float weight;
    CDate current;
    public:
    virtual void display(CDate&) = 0;
    Pet(string name,float length,float weight,CDate current):\
    name(name),length(length),weight(weight),current(current){}
};

class Cat : public Pet {
    public:
    Cat(string name,float length,float weight,CDate current):\
    Pet(name,length,weight,current){}
    void display(CDate& date) {
        if(current.year < date.year ||\
        current.year == date.year && current.month < date.month ||\
        current.year == date.year && current.month == date.month && current.day < date.day) {
            cout << "error" << endl;
            return;
        }
        int gap = cal_gap_day(date.year,date.month,date.day,\
        current.year,current.month,current.day);
        cout << name << " after " << gap << " day:" <<\
        " length=" << fixed << setprecision(2) << length+gap*0.1 << "," << "weight="\
        << setprecision(2) << weight+gap*0.2 << endl;
    }
};

class Dog : public Pet {
    public:
    Dog(string name,float length,float weight,CDate current):\
    Pet(name,length,weight,current){}
    void display(CDate& date) {
        if(current.year < date.year || current.month < date.month\
        || current.day < date.day) {
            cout << "error" << endl;
            return;
        }
        int gap = cal_gap_day(date.year,date.month,date.day,\
        current.year,current.month,current.day);
        cout << name << " after " << gap << " day:" <<\
        " length=" << fixed << setprecision(2) << length+gap*0.2 << ","\
        << "weight=" << setprecision(2) << weight+gap*0.1 << endl;
    }
};


int main(){
    int T;cin >> T;
    int year,month,day;cin >> year >> month >> day;
    CDate flag(year,month,day);
    while(T--) {
        string name; float length,weight; int type;
        cin >> type >> name >> length >> weight >> year >> month >> day;
        CDate current(year,month,day);
        if(type == 1) {
            Cat cat(name,length,weight,current);
            cat.display(flag);
        } else {
            Dog dog(name,length,weight,current);
            dog.display(flag);
        }
    }
}