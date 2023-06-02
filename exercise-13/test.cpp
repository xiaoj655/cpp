#include<bits/stdc++.h>

using namespace std;

int get (int year ,int month, int day,int year2 ,int month2 ,int day2) {
  int sum1[13]={0};
        int sum2[13]={0};
        int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31,};
        auto f=[&](int year)->bool {return !(year%4) && (year%100) || !(year%400);};
        auto init=[&](int year,int*const sum)->void{
            if(f(year))a[2]=29;
            else a[2]=28;
            for(int i=1;i<=12;i++) sum[i]=a[i]+sum[i-1];
        };

        int ret=0;
        if(year==year2){
            if(month==month2){
                ret+=day2-day;
            }else{
                init(year2,sum2);
                ret+=sum2[month2-1]+day2;
                init(year,sum1);
                ret+=-sum1[month-1]-day;
            }
        }else{
            init(year,sum1);
            ret+=sum1[12]-sum1[month-1]-day;
            init(year2,sum2);
            ret+=sum2[month2-1]+day2;
            for(int i=year+1;i<year2;i++){
                ret+=f(i)?366:365;
            }
        }
        return ret;   
}

int main () {
  int a,b,c;
  cin >> a >> b >> c;
  cout << get(0,1,1,a,b,c);
}