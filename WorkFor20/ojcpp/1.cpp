#include<bits/stdc++.h>

using namespace std;

class product{
private:
    int __type__;
    string __name__;
    int __rent__;
    bool __state__;
public:
    product(int type,string name,int rent,bool state)
    :__type__(type),__name__(name),__rent__(rent),__state__(state){;}
    bool check();
    void getrent(int a);
};

bool product::check()
{
    switch (__type__){
    case 1:cout<<"黑胶片";break;
    case 2:cout<<"CD";break;
    case 3:cout<<"VCD";break;
    case 4:cout<<"DVD";break;
    }
    cout<<'['<<__name__<<']';
    if(__state__)cout<<"已出租";
    else cout<<"未出租";
    return __state__;
}

void product::getrent(int times)
{
    if(check())
        cout<<"\n当前租金为"<<__rent__*times;
    else 
        cout<<"\n未产生租金";
}


signed main(void)
{
    int  t;cin>>t;
    while(t--){
        //制品信息包括：类型、名称、租金单价、状态。
        int type;
        string name;
        int rent;
        bool state;
        cin>>type>>name>>rent>>state;
        product var(type,name,rent,state);
        int op;cin>>op;
        if(op){
            var.getrent(op);
        }else{
            var.check();
        }
        cout<<endl;
    }

    return 0;
}