#include<bits/stdc++.h>

using namespace std;

class Vector {
    int x, y;
    public:
        Vector(int x, int y):x(x),y(y){}
        Vector() = default;
        Vector operator+(const Vector& v) const {
            Vector result;
            result.x = x + v.x;
            result.y = y + v.y;
            return result;
        }
        int get_x () {
            return x;
        }
        int get_y () {
            return y;
        }
};

int main() {
    Vector v1 = {1, 2};
    Vector v2 = {3, 4};
    Vector v3 = v1 + v2; // 调用重载的 + 运算符
    cout << v3.get_x() << " " << v3.get_y() << endl; // 输出 "4 6"
    return 0;
}
