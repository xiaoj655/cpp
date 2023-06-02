#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;


class CDate
{
    private:
        int year, month, day;
    public:
        CDate() : year(0), month(0), day(0) {}    
        CDate(int y, int m, int d);
        bool isLeapYear();
        bool isExpired();
        int getYear();
        int getMonth();
        int getDay();
        int getDayofYear();
        int calAvaliableDays();
};
 
CDate::CDate(int y, int m, int d)
{ 
    year = y, month = m,day = d;
}
 
bool CDate::isLeapYear()
{ 
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; 
}
 
int CDate::getYear()
{ 
    return year;
}
 
int CDate::getMonth() 
{ 
    return month;
}
 
int CDate::getDay() 
{ 
    return day;
}
 
int CDate::getDayofYear()

{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear())
    {
        a[2]++;
    }
    // 求日期的天数
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}

bool CDate::isExpired(){
    if(year < 2015) return true;
    else if(year == 2015){
        if(month < 4) return true;
        else if(month == 4){
            if(day < 7) return true;
            else return false;
        }else return false;
    } else return false;
}

int CDate::calAvaliableDays(){
    int avaliableDays=0;
    for(int i=2016;i<year;i++){
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) avaliableDays += 366;
        else avaliableDays += 365; 
    }
    avaliableDays += day;
    return avaliableDays;
}


class CD{
    char* name_;
    char cdtype_;
    char medium_;
    CDate data_;
    public:
    CD(char* name,char cdtype,char medium,int a,int b, int c):name_(name),cdtype_(cdtype),medium_(medium),data_(a,b,c){}
    CD(CD& old){
        name_ = old.name_;
        cdtype_ = 'B';
        medium_ = 'H';
    }
    void myPrint(){
        const string cdtype = [this]() {
        switch (cdtype_)
        {
        case 'O':
            return "origin";
        case 'T':
            return "trial";
        case 'B':
            return "backup";
        default:
            return "unknown";
        }
    }();
    const string medium = [this]() {
        switch (cdtype_)
        {
        case 'D':
            return "optical disk";
        case 'H':
            return "hard disk";
        case 'U':
            return "USB disk";
        default:
            return "unknown";
        }
    }();
        cout << "name:" << name_ <<endl <<"type:"<<cdtype<<endl<<"media:"<<medium<<endl;
        if()
    }
};

int main(){
    int T;cin >> T;
    while(T--){
        char name[31];char cdtype;char medium;int a,b,c;
        cin >> name >> cdtype >> medium >> a >> b >> c ;
    }

}