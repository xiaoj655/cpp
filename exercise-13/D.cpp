#include<bits/stdc++.h>

using namespace std;
class Vector
{
private:
    int vec[5];
public:
    Vector(int v[]){
      for(int i=0 ;i<5;i++){
        vec[i]=v[i];
      }
    };
    Vector() = default;
    Vector operator +(const Vector& obj);
    Vector operator -(const Vector& obj);
    void print() {
      for (int i=0;i<5;i++){
        cout << vec[i] << ' ';
      };
      cout << endl;
    };
};

Vector Vector::operator+(const Vector& obj){
  int* v= new int[5];
  for(int i=0;i<5;i++){
    v[i] = obj.vec[i] + vec[i];
  }
  return Vector(v);
}
Vector Vector::operator-(const Vector& obj){
  int* v= new int[5];
  for(int i=0;i<5;i++){
    v[i] = vec[i] - obj.vec[i];
  }
  return Vector(v);
}
int main(){
  int arr[5];
  for(int i=0;i<5;i++){
    cin >> arr[i];
  }
  Vector a(arr);
  for(int i=0;i<5;i++){
    cin >> arr[i];
  }
  Vector b(arr);
  (a+b).print();
  (a-b).print();
  return 0;
}