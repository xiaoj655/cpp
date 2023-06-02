#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

class Student;
void ANS(Student var1,Student var2 );

class Student{
private:
    string name;
    int year,month,day;
public:
    string Getname(){return name;}
    int Getyear(){return year;}
    int Getmonth(){return month;}
    int Getday(){return day;}
    Student(){;}
    Student(string name,int year, int month ,int day):name(name),year(year),month(month),day(day){;}
    ~Student(){;}
    // Student& operator=(Student& var){
        
    //     return *this;
    // }
    friend int operator-(Student var1,Student var2){
        int sum1[13]={0};
        int sum2[13]={0};
        int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31,};
        auto f=[&](int year)->bool {return !(year%4) && (year%100) || !(year%400);};
        if(var1.year>var2.year || var1.year==var2.year &&  var1.month>var2.month ||var1.year==var2.year &&  var1.month==var2.month &&  var1.day>var2.day){
            swap(var1,var2);
        }

        auto init=[&](int year,int*const sum)->void{
            if(f(year))a[2]=29;
            else a[2]=28;
            for(int i=1;i<=12;i++) sum[i]=a[i]+sum[i-1];
        };

        int ret=0;
        if(var1.year==var2.year){
            if(var1.month==var2.month){
                ret+=var2.day-var1.day;
            }else{
                init(var2.year,sum2);
                ret+=sum2[var2.month-1]+var2.day;
                init(var1.year,sum1);
                ret+=-sum1[var1.month-1]-var1.day;
            }
        }else{
            init(var1.year,sum1);
            ret+=sum1[12]-sum1[var1.month-1]-var1.day;
            init(var2.year,sum2);
            ret+=sum2[var2.month-1]+var2.day;
            for(int i=var1.year+1;i<var2.year;i++){
                ret+=f(i)?366:365;
            }
        }
        return ret;   
    }
    friend void ANS(Student& var1,Student& var2,int ans){
        cout<<var1.name;
        cout<<string("和");
        cout<<var2.name;
        cout<<string("年龄相差最小，为");
        cout<<ans;
        cout<<string("天。");
    }
};


signed main(void)
{
    // system("chcp 65001");
    int t;
    cin>>t;
    Student* ptr=new Student[t];
    for(int i=0;i<t;i++){
        string name;int year,month,day;cin>>name>>year>>month>>day;
        ptr[i]=Student(name,year,month,day);
    }

    // sort(ptr,ptr+t);
    
    int minn=INT_MAX;
    int minnindex1=0;
    int minnindex2=0;
    for(int i=0;i<t;i++){
        for(int j=i+1;j<t;j++){
            int val=abs(ptr[j]-ptr[i]);
            if(minn>val){
                minn=val;
                minnindex1=i;
                minnindex2=j;
            }
        }
    }

    ANS(ptr[minnindex1],ptr[minnindex2],minn);

    delete[] ptr; 
    return 0;
}