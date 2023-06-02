#include<bits/stdc++.h>

using namespace std;

class CVehicle{
  protected:
    double max_speed, speed, weight;
  public:
    CVehicle() = default ;
    CVehicle(double m,double s, double w):\
    max_speed(m), speed(s), weight(w){}
    virtual void display() {
      cout << "Vehicle:" << endl;
      cout << "max_speed:" << max_speed << endl;
      cout << "speed:" << speed << endl;
      cout << "weight:" << weight << endl;
      cout << endl;
    }
};
class CBicyle : virtual public CVehicle {
  protected:
    double height;
  public:
  CBicyle(double m,double s, double w, double h)\
  :CVehicle(m,s,w), height(h){}
    void display(){
      cout << "Bicycle:" << endl;
      cout << "max_speed:" << max_speed << endl;
      cout << "speed:" << speed << endl;
      cout << "weight:" << weight << endl;
      cout << "height:" << height << endl;
      cout << endl;
    }
};
class CMotocar : virtual public CVehicle {
  protected:
    int seat_num;
  public:
    CMotocar(double m,double s, double w,int se):\
    CVehicle(m,s,w),seat_num(se){}
    void display(){
      cout << "Motocar:" << endl;
      cout << "max_speed:" << max_speed << endl;
      cout << "speed:" << speed << endl;
      cout << "weight:" << weight << endl;
      cout << "seat_num:" << seat_num << endl;
      cout << endl;
    }
};
class CMotocycle : public CMotocar, public CBicyle {
  public:
    CMotocycle(double m,double s, double w,int se,double h):\
    CMotocar(m,s,w,se), CBicyle(m,s,w,h),CVehicle(m,s,w){}
    void display(){
      cout << "Motocycle:" << endl;
      cout << "max_speed:" << max_speed << endl;
      cout << "speed:" << speed << endl;
      cout << "weight:" << weight << endl;
      cout << "height:" << height << endl;
      cout << "seat_num:" << seat_num << endl;
      cout << endl;
    }
};
int main(){
  double m,s,w,h;int se;
  cin >> m >> s >> w >> h >> se;
  CVehicle(m,s,w).display();
  CBicyle(m,s,w,h).display();
  CMotocar(m,s,w,se).display();
  CMotocycle(m,s,w,se,h).display();
}