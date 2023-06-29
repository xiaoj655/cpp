#include<bits/stdc++.h>

using namespace std;

#define width(x) setw(x)<<setfill('0')
class Date;
class Time;
class Work;

class Date{
private:

protected:
    int __year__;
    int __month__;
    int __day__;
public:
    Date(int year,int month,int day)
    :__year__(year),__month__(month),__day__(day){;}
};

class Time{
protected:
    int __hour__;
    int __minute__;
    int __second__;
public:
    Time(int hour,int minute,int second)
    :__hour__(hour),__minute__(minute),__second__(second){;}
};

bool before(const Work& w1,const Work& w2);

class Work:public Date,Time{
private:
    int __id__;
public:
    Work* __Next__;
    Work(int year,int month,int day,int hour,int minute,int second,int id)
    :__id__(id),Time( hour, minute, second),Date( year, month, day){__Next__=nullptr;}
    friend bool before(const Work& w1,const Work& w2); 
    friend ostream& operator<<(ostream& out,const Work &var){out<<var.__id__<<": "<<var.__year__<<"/"<<width(2)<<var.__month__<<"/"<<width(2)<<var.__day__<<" "<<width(2)<<var.__hour__<<":"<<width(2)<<var.__minute__<<":"<<width(2)<<var.__second__;return out;}
};

/*
<<"/"<<
<<":"<<
out<<"The urgent Work is No."<<id<<year<<"/"<<month<<"/"<<day<<hour<<":"<<minute<<":"<<second
*/


bool before(const Work& w1,const Work& w2)
{
    stringstream ss1;
    ss1<<width(4)<<w1.__year__<<width(2)<<w1.__month__<<width(2)<<w1.__day__<<width(2)<<w1.__hour__<<width(2)<<w1.__minute__<<width(2)<<w1.__second__;
    stringstream ss2;
    ss2<<width(4)<<w2.__year__<<width(2)<<w2.__month__<<width(2)<<w2.__day__<<width(2)<<w2.__hour__<<width(2)<<w2.__minute__<<width(2)<<w2.__second__;
    string str1,str2;
    ss1>>str1;ss2>>str2;
    return (str1<str2);
}



signed main(void)
{
    int id;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    typedef Work* Wp;
    
    cin>>id>>year>>month>>day>>hour>>minute>>second;
    Wp head=new Work{year,month,day,hour,minute,second,id};
    // Work* head=new Work(id,year,month,day,hour,minute,second);

    Work *prv=head,*cur=nullptr;
    while(cin>>id,id){
        cin>>year>>month>>day>>hour>>minute>>second;
        Wp cur=new Work{year,month,day,hour,minute,second,id};
        prv->__Next__=cur;
        prv=cur;
    }

    Wp ans=head;
    for(Wp i=head;i->__Next__;i=i->__Next__){
        if( before(*i,*ans) )
            ans=i;
    }
    cout<<"The urgent Work is No."<<*ans;

    prv=head;cur=head->__Next__;
    while (cur){
        delete prv;
        prv=cur;
        cur=cur->__Next__;
    }
    delete prv;

    return 0;
}