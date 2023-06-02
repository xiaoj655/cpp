#include<bits/stdc++.h>

using namespace std;

class Fraction
{
private:
    int fz, fm;
    void contracted() {
        int flag = 0;
        do{
            flag=0;
            for(int i=9;i > 1;i--){
                if(fz%i == 0 && fm%i ==0){
                    fz /= i; fm /= i;
                    flag=1;
                }
            }
        }while(flag);
    }; 
public:
    Fraction():fz(0),fm(1){};
    Fraction(int x, int y):fz(x), fm(y){}
    Fraction operator+(Fraction b);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    void say () {
        cout << "fraction=" << fz << '/' << fm << endl;
    }
};

Fraction Fraction::operator+(Fraction b){
    return Fraction(fm*b.fz+b.fm*fz,fm*b.fm);
}
Fraction Fraction::operator-(Fraction other){
    return Fraction(-fm*other.fz+other.fm*fz,fm*other.fm); 
}
Fraction Fraction::operator*(Fraction other){
    return Fraction(fz*other.fz,fm*other.fm); 
}
Fraction Fraction::operator/(Fraction other){
    return Fraction(fz*other.fm, fm*other.fz);
}
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    (Fraction(a,b)+Fraction(c,d)).say();
    (Fraction(a,b)-Fraction(c,d)).say();
    (Fraction(a,b)*Fraction(c,d)).say();
    (Fraction(a,b)/Fraction(c,d)).say();
}