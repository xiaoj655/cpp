#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class CVector{
    int* _data; int _n;
    public:
    CVector(int* arr,int n):_n(n){
        _data = new int[n];
        memcpy(_data, arr, _n*sizeof(arr[0]));
    }
    CVector(){
        _n = 5;
        _data = new int[_n];
        for(int i=0;i<5;i++){
            _data[i] = i;
        }
    }
    ~CVector(){
        delete[] _data;
    }
    void say(){
        for(int i=0;i<_n - 1;i++){
            cout << _data[i] << ' ' ;
        }
        cout << _data[_n-1];
        cout << endl;
    }
};


int main(){
    CVector vector1;
    int n;cin >> n;int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    CVector vector2(arr,n);
    vector1.say();vector2.say();
}