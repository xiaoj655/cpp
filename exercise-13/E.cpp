#include<bits/stdc++.h>

using namespace std;
int md1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int md2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int sum1[13],sum2[13];
int run (int x) {
	if(x%4==0&&x%100!=0 || x%400==0) return 1;
	return 0;
}
class stu {
	string name ;int year,month,day;
	public:
	stu() = default ;
	stu(string name,int year, int month ,int day):\
	name(name), year(year), month(month), day(day){}
	friend int operator-(stu& a,stu& b) {
		return cal(a,b);
	}
	friend int cal(stu&,stu&);
	string getname () { return name; }
};
int cal(stu& a, stu& b){
	int start[3],end[3],res=0;
	if(a.year < b.year){
		start[0] = a.year;
		start[1] = a.month;
		start[2] = a.day;
		end[0] = b.year;
		end[1] = b.month;
		end[2] = b.day;
	} else {
		start[0] = b.year;
		start[1] = b.month;
		start[2] = b.day;
		end[0] = a.year;
		end[1] = a.month;
		end[2] = a.day;
	}
	for(int i=start[0]; i<end[0] ;i++){
		if (run(i+1)) res += 366;
		else res += 365;
	}
	if(run(end[0])){
		res += sum2[end[1]-1] - sum2[start[1]-1];
	} else {
		res += sum1[end[1]-1] - sum1[start[1]-1];
	}
	res += end[2] - start[2];
	return res;
}
int main(){
	int min = 0x7fffffff,x,y;
	for(int i=1;i<13;i++) sum1[i] += sum1[i-1] + md1[i-1];
	for(int i=1;i<13;i++) sum2[i] += sum2[i-1] + md2[i-1];
 	int n;cin >> n;
	stu* stus = new stu[n];
	string name;int year,month,day;
	for(int i=0;i<n;i++){
		cin >> name >> year >> month >> day;
		stus[i] = stu(name,year,month,day);
	}
	for (int i=0;i<n;i++) {
		for (int k=i+1; k<n ;k++) {
			if(abs(stus[i]-stus[k])<min){
        if(stus[i]-stus[k] == min) continue ;
				x=i;y=k;
				min = abs(stus[i]-stus[k]);
			}
		}
	}
	cout << stus[x].getname() << "和" << stus[y].getname() << "年龄相差最小，为" << abs(min) << "天。";
}