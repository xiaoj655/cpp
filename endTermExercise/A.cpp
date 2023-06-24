#include <bits/stdc++.h>

using namespace std;

class product
{
    int type, price, status;
    string name;

public:
    product() = default;
    product(int type, int price, int status, string name) : type(type),\
    price(price), status(status), name(name) {}
    void print()
    {
        switch (type)
        {
        case 1:
            cout << "黑胶片";
            break;
        case 2:
            cout << "CD";
            break;
        case 3:
            cout << "VCD";
            break;
        case 4:
            cout << "DVD";
            break;
        }
        cout << "[" << name << "]";
        if (status)
            cout << "已出租";
        else
            cout << "未出租";
        cout << endl;
    }
    void cal_rent()
    {
        int used_days;
        cin >> used_days;
        if (!used_days)
            return;
        if (status)
            cout << "当前租金为" << used_days * price;
        else
            cout << "未产生租金";
        cout << endl;
    }
};

int main()
{
    int T;
    cin >> T;
    product *pro;
    while (T--)
    {
        int a, b, c;
        string n;
        cin >> a >> n >> b >> c;
        pro = new product(a, b, c, n);
        pro->print();
        pro->cal_rent();
        delete pro;
    }
}