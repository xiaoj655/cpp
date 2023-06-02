#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

class Point{
    double x_,y_;
    public:
    Point(double x,double y):x_(x),y_(y){}
    friend double Distance(Point& a,Point& b);
};
double Distance(Point& a,Point& b){
    return std::sqrt(pow(a.x_-b.x_,2)+pow(a.y_-b.y_,2));
}
int main(){
    int T;cin >> T;
    for(;T != 0;T--){
        double x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1,y1),p2(x2,y2);
        cout << std::fixed << std::setprecision(0) << Distance(p1,p2) << endl;
    }
}