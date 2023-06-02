#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Account
{
private:
    static float count_; // 账户总余额
    static float interestRate_;
    string accno_, accname_;
    float balance_;
public:
    Account(){}
    Account(string ac, string na, float ba):accno_(ac),accname_(na),balance_(ba){}
    void deposit(float amount){balance_ += amount;} // 存款
    void withdraw(float amount){balance_ -= amount;} // 取款
    float getBalance(); // 获取账户余额
    void show(float in,float out); // 显示账户所有基本信息
    static void getCount(){
        cout << count_ ;
    } // 获取账户总余额
    static void setInterestRate(float rate){
        interestRate_ = rate;
    } // 设置利率
    void getInterestRate(){
        balance_ *= (1 + interestRate_);
    } // 获取利率
};

float Account::count_ = 0;
float Account::interestRate_ = 0;

void Account::show(float in,float out){
    deposit(in);
    cout << accno_ << ' ' << accname_ << ' ' << balance_ <<' ';
    getInterestRate();
    cout << balance_ << ' ';
    withdraw(out);
    cout << balance_ << endl;
    Account::count_ += balance_;
}
int main(){
    double rate;
    int n;cin >> rate >> n;
    Account::setInterestRate(rate);
    Account* acc = new Account[n];
    for(int i =0;i < n ;i ++){
        string ac,na;float ba,in,out;
        cin >> ac >> na >> ba >> in >> out;
        acc[i] = Account(ac,na,ba);
        acc[i].show(in,out);
    }
    Account::getCount();
}