#include<iostream>
#include<cstring>
#include<typeinfo>


using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){
    int* arr = new int[3];
    cout << typeid(delete(arr)).name();
}