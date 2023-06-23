#include<bits/stdc++.h>

using namespace std;

template<class T>
void fun(void) {
    T x[6];
    bool flag=true;
    for (int i=0;i<6;i++) {
        cin >> x[i];
    }
    for(int i=1;i<6;i++){
        if(x[i-1] > x[i]) {
            flag = false;
            cout << "Invalid\n";
            break;
        }
    }
    if (flag) cout << "Valid\n";
}
int main(){
    char x;
    while (cin >> x && x != EOF){
        switch (x)
        {
        case 'i':
            fun<int>();
            break;
        case 'c':
            fun<char>();
            break;
        default:
            fun<float>();
            break;
        }
    }
}