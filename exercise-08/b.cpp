#include<iostream>

class con {
        int a;
    public:
        con():a(0){
            std::cout<<"Constructed by default, value = 0"<<std::endl;
        }
        con(int x):a(x){
            std::cout<<"Constructed using one argument constructor, value = "<< x << std::endl;
        }
        con(con& x){
            a = x.a;
            std::cout<<"Constructed using copy constructor, value = " << x.a <<std::endl;
        }
};

int main(){
    int T;std::cin>> T;
    while(T--){
        int para,para2;std::cin>>para;
        switch (para)
        {
        case 0:{
            con a1;
            break;}
        case 1:{
            std::cin >> para2;
            con a2(para2);
            break;}
        case 2:{
            std::cin>>para2;
            con a3(para2);
            con a4(a3);
            break;}
    }
}
return 0;
}