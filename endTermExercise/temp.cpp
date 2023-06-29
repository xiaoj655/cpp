#include<bits/stdc++.h>

using namespace std;

class Complex {
    public:
    int x,y;
    Complex(int x, int y): x(x),y(y){ }
    Complex() = default;
    Complex operator+ (Complex& other) {
        Complex res;
        res.x = x+other.x;
        res.y = y+other.y;
        return res;
    }
};

int main(){
    Complex a = {1,2};
    Complex b = {2,3};
    cout << "x: "<< (a+b).x << '\n' << "y: "<< (a+b).y;
    cout << (a+b)+(a+b);
}
