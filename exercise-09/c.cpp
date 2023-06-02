#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class Complex
{
private:
	double real; // 实部
	double imag; // 虚部
public:
	Complex():real(0),imag(0){}
	Complex(double r, double i):real(r),imag(i){}
	// 友元函数，复数c1 + c2(二参数对象相加)
	// friend Complex addCom(const Complex& c1, const Complex& c2);
    // friend Complex lessCom(const Complex& c1, const Complex& c2);
	// 友元函数，输出类对象c的有关数据(c为参数对象)
	friend void outCom(const Complex& c);
    Complex operator+(const Complex &other) const{
        Complex res;
        res.real = real + other.real;
        res.imag = imag + other.imag;
        return res;
    }
    Complex operator-(const Complex &other) const{
        Complex res;
        res.real = real - other.real;
        res.imag = imag - other.imag;
        return res;
    }
};
// Complex addCom(const Complex& c1, const Complex& c2){
//     return Complex(c1.real+c2.real,c1.imag+c2.imag);
// }
// Complex lessCom(const Complex& c1, const Complex& c2){
//     return Complex(c1.real-c2.real,c1.imag-c2.imag);
// }
    
void outCom(const Complex& a){
    cout << '(' << a.real << ',' << a.imag << ')' <<endl;
}
int main(){
    double a,b;cin >> a >> b; Complex x(a,b);
    int t;cin >> t;
    while(t--){
        char op;cin >> op >> a >> b;
        Complex y(a,b);
        switch (op)
        {
        case '+':
            // x = addCom(x,y);
            outCom(x = x+y);
            break;
        
        default:
            // x = lessCom(x,y);
            outCom(x = x-y);
            break;
        }       
    }
}