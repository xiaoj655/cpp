#include<bits/stdc++.h>

using namespace std;

template<int N>
class Fac {
    public:
    const static int value= N * Fac<N - 1>::value;
};

template<>
class Fac<0> {
    public:
    const static int value = 1;
};


int main(){
    cout << "Fac: " << Fac<4>::value;
}