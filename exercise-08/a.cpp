#include<iostream>
#include <cstdlib>
#include<cmath>
#include <iomanip>
float res1,res2;

class Equation{
    float a=1,b=1,c=0;

    public:
        void set(float ia,float ib ,float ic);
        int getRoot(float& res1,float&res2);
};

int Equation::getRoot(float& res1,float&res2){
    float delta = b*b - 4*a*c;
    res1 = (-1) * b/(2*a);
    res2 = sqrt(std::abs(delta))/(2*a);
    if(delta == 0) return 0;
    else if (delta > 0) return 1;
    else return -1;
}

void Equation::set(float ia,float ib ,float ic){
    a= ia;b= ib ;c = ic;
}

int main(){
    int T;Equation eqa;
    std::cin >> T;
    while(T--){
        float x,y,z;
        std::cin >> x >> y >> z;
        eqa.set(x,y,z);
        switch(eqa.getRoot(res1,res2)){
            case 0:
                std::cout << std::fixed<<std::setprecision(2)<<"x1=x2=" << res1 << std::endl ;
                break;
            case 1:
                std::cout << std::fixed<<std::setprecision(2)<<"x1=" << res1+res2 <<" x2="<<res1-res2<<std::endl;
                break;
            case -1:
                std::cout << std::fixed<<std::setprecision(2)<<"x1=" << res1 <<'+'<<res2<<'i'<<' '<<"x2="<<res1<<'-'<<res2<<'i'<<std::endl;
                break;
        }
    }
}