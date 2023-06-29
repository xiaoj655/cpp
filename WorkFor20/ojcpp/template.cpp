#include<bits/stdc++.h>

using namespace std;

class Date{
private:
protected:
public:
    // Date()=default;
    Date();
    Date(const Date& var);
    ~Date();
    Date(const Date&& var);
    Date& operator=(const Date& var);
    Date& operator=(const Date&& var);
};

#define width(x) setw(x)<<setfill('0')

signed main(void)
{  
    stringstream ss1;
    // ss1<<setw()
    ss1<<1077<<width(2)<<2<<3;
    string str1;
    ss1>>str1;
    cout<<str1<<'\n';

    stringstream ss2;
    ss2<<2000<<2<<3;
    string str2;
    ss2>>str2;
    // cout<<str2;
    // cout<<(str1>str2)<<'\n';
    // cout<<((str1>str2)?"birgger":"smaller")<<'\n';

    return 0;
}