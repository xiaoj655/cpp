#include<bits/stdc++.h>

using namespace std;

class Data {
    protected:
    int year,month,day;
    public:
    Data (int year,int month,int day):year(year),\
    month(month),day(day){}
};

class Time {
    protected:
    int hour,minute,second;
    public:
    Time(int hour,int minute , int second):\
    hour(hour),minute(minute),second(second){}
};

class Work : public Data, public Time {
    int id;
    public:
    Work(int y,int m,int d,int h, int min, int s,\
    int id):Data(y,m,d),id(id),Time(h,min,s){}
    friend Work& get_earlier (Work&,Work&);
    void say () {
        cout << "The urgent Work is No." << id\
    <<": " << year << "/" << setw(2) << setfill('0')\
    << setbase(10) << month \
    << "/" << setw(2) << day << " " << setw(2) <<  hour \
    << ":" << setw(2) << minute << ":" << setw(2) << second;
    }
};

Work& get_earlier (Work& a, Work& b) {
    // if (a.year != b.year) {
    //     if (a.year > b.year) return b;
    //     return a;
    // } else {
    //     if (a.month != b.month) {
    //         if (a.month > b.month) return b;
    //         return a;
    //     } else {
    //         if (a.day != b.day) {
    //             if (a.day > b.day) return b;
    //             return a;
    //         } else {
    //             if (a.hour != b.hour) {
    //                 if(a.hour > b.hour) return b;
    //                 return a;
    //             } else {
    //                 if (a.minute != b.minute) {
    //                     if (a.minute > b.minute) return b;
    //                     return a;
    //                 } else {
    //                     if(a.second > b.second) return b;
    //                     return a;
    //                 }
    //             }
    //         }
    //     }
    // }

    //This is a better realized way relatived with up!!
    vector<int> a_time = {a.year,a.month,a.day,a.hour,a.minute,a.second};
    vector<int> b_time = {b.year,b.month,b.day,b.hour,b.minute,b.second};
    for(int i=0; i<6 ;i++) {
        if (a_time[i] != b_time[i]) {
            if (a_time[i] < b_time[i]) return a;
            return b;
        }
    }
    return a;
}

int main(){
    int id,y,m,d,h,min,s;
    Work* works[100];
    int cnt=0;
    while (cin >> id,id) {
        cin >> y >> m >> d >> h >> min >> s;
        works[cnt++] = new Work(y,m,d,h,min,s,id);
    }

    Work& earliest= *works[0];

    for(int i=1;i<cnt;i++){
        earliest = get_earlier (earliest,\
        *works[i]);
    }
    earliest.say();
    // delete[] works;
}