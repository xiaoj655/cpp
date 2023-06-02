#include<bits/stdc++.h>

using namespace std;

class CDate
{
private:
	int year; int month; int day;
public:
	int Getyear(){return year;}
	CDate(int vyear, int vmonth, int vday):year(vyear),month(vmonth),day(vday){;}
	inline bool isLeap(int n){return !(n%4) && (n%100) || !(n%400);}
	bool check(){
		int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31,};
		if(isLeap(year)){
			a[2]++;
		}
		return  month >=1 && month <=12 && day>=1 && day<=a[month] && year>=0;
	}
	void Getdate(char *temp){
		int power=1000;
		for(int i=0;i<4;i++,power/=10){
			temp[i]=year/power%10;
			temp[i]+='0';
		}
		power=10;
		for(int i=4;i<6;i++,power/=10){
			temp[i]=month/power%10;
			temp[i]+='0';
		}
		power=10;
		for(int i=6;i<8;i++,power/=10){
			temp[i]=day/power%10;
			temp[i]+='0';
		}
	}
	
	bool isoutdate(int validYear){
		if(year+validYear<2021 ){
			return true;
		}else if(year+validYear==2021){
			if(month<11){
				return true;
			}else if(month == 11){
				if(day<9){
					return true;
				}	
			}
		}
		return false;
	}
	
	void print(){cout<< year<<"年"<<month<<"月"<<day<<"日";}
};

class COldId{
protected:
	char* pId15, * pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldId(char* pIdVal, char* pNameVal, CDate& day)
	:birthday(day){
		pId15=new char[strlen(pIdVal)];
		pName=new char[strlen(pNameVal)];
		sprintf(pId15,"%s",pIdVal);
		sprintf(pName,"%s",pNameVal);
		//		printf("%s %s\n",pId15,pName);
	}
	// bool check(){;}
	void print(){;}
	~COldId(){delete pId15,pName;}
};

class CNewId:public COldId{
private:
	char* pId18;
	CDate issueDay;
	int validYear;
public:
	CNewId(char* nameVal,char* pId15Val,char* pId18Val,CDate& Cday,CDate&  IssueDay,int Vaild)
	:COldId(pId15Val,nameVal,Cday),validYear(Vaild),issueDay(IssueDay){
		pId18=new char[strlen(pId18Val)];  
		sprintf(pId18,"%s",pId18Val);
	}
	virtual bool check(){
		//4. 身份证号码的长度正确.
		int len=strlen(pId18);
		if(len!=18)return false;
		
		//1. 确认18位号码是从15位号码扩展的
		for(int i=0;i<6;i++){
			if(pId15[i]!=pId18[i]){
				return false;
			}
		}
		
		if(pId18[6]!='1'|| pId18[7]!='9')
			return false;
		
		for(int i=6;i<15;i++){
			if(pId15[i]!=pId18[i+2]){
				return false;
			}
		}
		
		
		//3. 身份证号码中不含非法字符.
		for(int i=0;i<len;i++){
			if(pId18[i]>='0' && pId18[i]<='9');
			else return false;
		}
		
		
		//1.且第18位校验码正确
		char table[]="10X98765432";
		long long sum=(pId18[0]-'0')*7+(pId18[1]-'0')*9+(pId18[2]-'0')*10+
		(pId18[3]-'0')*5+(pId18[4]-'0')*8+(pId18[5]-'0')*4+(pId18[6]-'0')*2+
		(pId18[7]-'0')*1+(pId18[8]-'0')*6+(pId18[9]-'0')*3+(pId18[10]-'0')*7+
		(pId18[11]-'0')*9+(pId18[12]-'0')*10+(pId18[13]-'0')*5+(pId18[14]-'0')*8+
		(pId18[15]-'0')*4+(pId18[16]-'0')*2;
		sum%=11;
		
		if(pId18[17]!=table[sum])return false;
		
		//2. 身份证中的出生日期合法.
		char temp2[30];
		birthday.Getdate(temp2);
		
		
		char temp=pId18[14];
		pId18[14]=0;
		if(strcmp(pId18+6,temp2))return false;
		pId18[14]=temp;
		
		temp=pId15[12];
		pId15[12]=0;
		if(strcmp(pId15+6,temp2+2))return false;
		pId15[12]=temp;
		//5. 身份证目前处于有效期内，假设当前日期为2021年11月9日。
		return birthday.check() && issueDay.check() && !issueDay.isoutdate(validYear);
	}
	void print(){
		cout<<pName<<'\n';
		if( check() ){
			cout<<pId18<<' ';
			birthday.print();
			if(validYear==100)
				cout<<" 长期\n";
			else
				cout<<' '<<validYear<<'\n';
		}else{
			cout<<"illegal id\n";
		}
	}
	~CNewId(){delete pId18;}
};

signed main(void)
{
	int t;
	cin>>t;
	while(t--){
		char name[30];
		char pId15[30];
		char pId18[30];
		int year,month,day,vaild;
		int year2,month2,day2;
		cin>>name>>year>>month>>day>>pId15>>pId18>>year2>>month2>>day2>>vaild;
		// cout<<name<<year<<month<<day<<pId15<<pId18<<year2<<month2<<day2<<vaild<<'\n';
		CDate temp(year,month,day);
		CDate temp2(year2,month2,day2);
		CNewId var(name,pId15,pId18,temp,temp2,vaild);
		var.print();
	}
	return 0;
}