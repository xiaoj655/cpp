#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;


class Hotel
{
private:
    static int totalCustNum; // 顾客总人数
    static float totalEarning; // 旅店总收入
    static float rent; // 每个顾客的房租
    char *customerName; // 顾客姓名
    static int customerIdq; // 顾客编号
    int customerId;
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(){
        customerName = nullptr;
    }
    Hotel(char* customer){
        customerName = new char[std::strlen(customer)+1];
        std::strcpy(customerName,customer);
        totalCustNum++;
        customerIdq++;
        customerId = customerIdq;
        totalEarning += rent;
    }
    ~Hotel(){delete[] customerName;}; //记得delete customerName
    void Display(){
        cout << customerName << ' ' << customerId <<' '<< totalCustNum << ' '<< totalEarning <<endl;
    } //相应输出顾客姓名、顾客编号、总人数、总收入
    static void setRent(float a){rent = a;}
};

int Hotel::customerIdq = 20150000;
float Hotel::rent = 0;
int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;
int main(){
    float a ; cin >> a ; Hotel::setRent(a);
    for(;;){
        char* name = new char[30];
        cin >> name;
        if(name[0] == '0') break;
        Hotel(name).Display();
        
    }
}