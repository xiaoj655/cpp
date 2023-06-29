#include<bits/stdc++.h>


class Blob {
    char* a;
    size_t s;
    public:
    Blob() = default;
    Blob(int& s):s(s){
        std::cout << "first constructor" << std::endl;
        a = new char[s];
    }
    // Blob(int&& s):s(s){
    //     std::cout << "second constructor" << std::endl;
    //     a = new char[s];
    // }
    Blob(int s):s(s){
        std::cout << "third constructor" << std::endl;
        a = new char[s];
    }
};
int main(){
    Blob(1);
    int a=2;
    // Blob(a);
}