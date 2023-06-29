#include<bits/stdc++.h>

using namespace std;

class CDate;
class Pet;
class Cat;
class Dog;
int __gap__(CDate& var1,CDate& var2);
#define width(x) setw(x)<<setfill('0')


// template<class T>
// class counter{
// private:
//     T minn;
//     T maxn;
//     T pace_size;
// public(:)
//     counter(T minn=0,T maxn=,T pace_size)
//     :minn(minn),maxn(maxn),pace_size(pace_size){;}
// };
/*

*/

template<class T,class rules=T*>
class Accumlate{
public:
    T operator()(int ql,int qr,int times=1){return (ql>qr)?-1*(llabs(qr-ql)+1)*times:(llabs(qr-ql)+1)*times;}
    T operator()(int ql,int qr,int times,rules var);
    template<size_t N>
    T operator()(int ql,int qr,int (&a)[N]){int ret=0;for(int i=min(ql,qr);i<=max(ql,qr);i++)ret+=a[i];return (ql>qr)?-1*ret:ret;}
};

class CDate{
private:
    int __year__;
    int __month__;
    int __day__;
private:
    friend int __gap__(CDate& var1,CDate& var2);
public:
    friend int operator-(CDate& var1,CDate& var2);
    friend bool operator<(CDate& var1,CDate& var2);
    friend ostream&operator<<(ostream& out,const CDate&var){out<<var.__year__<<var.__month__<<var.__day__;return out;}
    friend istream&operator>>(istream& in,CDate& var){in>>var.__year__>>var.__month__>>var.__day__;return in;}
};


class Pet{ 
protected:
    string __name__;//姓名
    float __length__;//身长
    float __weight__;//体重
    CDate __current__;//开始记录时间
public:
    Pet(string name,float length,float weight,CDate current)
    :__name__(name),__length__(length),__weight__(weight),__current__(current){;}

    virtual void display(CDate day)=0;
    //输出目标日期时宠物的身长和体重

};


class Cat:public Pet{
private:

public:
    Cat(string name,float length,float weight,CDate current)
    :Pet(name,length,weight,current){;}
    void display(CDate day)override;
};


class Dog:public Pet{
private:

public:
    Dog(string name,float length,float weight,CDate current)
    :Pet(name,length,weight,current){;}
    void display(CDate day)override;
};


//realization ************************************
bool operator<(CDate& var1,CDate& var2)
{
    stringstream ss1;
    ss1<<width(4)<<var1.__year__<<width(2)<<var1.__month__<<width(2)<<var1.__day__<<width(2);
    stringstream ss2;
    ss2<<width(4)<<var2.__year__<<width(2)<<var2.__month__<<width(2)<<var2.__day__<<width(2);
    string str1,str2;
    ss1>>str1;ss2>>str2;
    return (str1<str2);
}


int __gap__(CDate& var1,CDate& var2)
{
    bool flag=(var2<var1);
    // bool flag=var1>var2; error!!!!
    if(flag)swap(var2,var1);
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31,};
    if ( [=](int n) -> bool {
            return !(n % 4) && n % 100 || !(n % 400);
        }(var2.__year__) ) {
    }a[2]++;

    int temp=0;
    Accumlate<int> acc;
    temp+=acc(var1.__year__,var2.__year__,365);
    temp+=acc(var1.__month__,var2.__month__,a);
    temp+=acc(var1.__day__,var2.__day__);
    return temp;
}

int operator-(CDate& var1,CDate& var2)
{
    return __gap__(var1,var2);
}

void Cat::display(CDate day)
{
    int temp;
    if((temp=__current__-day)>=0){
        cout<<__name__<<" after "<<temp<<" day: length="<<temp*0.1f<<",weight="<<temp*0.2f;
    }else cout<<"error";
}
//  <<" "<<  "<< <<"

void Dog::display(CDate day)
{
    int temp;
    if((temp=__current__-day)>=0){
        cout<<__name__<<" after "<<temp<<" day: length="<<temp*0.2f<<",weight="<<temp*0.1f;
    }else cout<<"error";
}


signed main(void)
{
    cout<<fixed<<setprecision(2);
    Pet *pt=nullptr;
    int t;cin>>t;
    CDate st;
    cin>>st;
    while(t--){
        int type;
        string name;
        float length;
        float weight;
        CDate current;
        cin>>type>>name>>length>>weight>>current;
        switch (type){
        case 1:{
            Dog(name,length,weight,current).display(st);  
            break;
        }
        case 2:{
            Cat(name,length,weight,current).display(st); 
            break;
        }
        }
        cout<<endl;
    }

    return 0;
}