#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class CVector{
    int* _data; int _n;
    public:
    static int sum;
    CVector(int* arr,int n):_n(n){
        _data = new int[n];
        memcpy(_data, arr, _n*sizeof(arr[0]));
        addSum();
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
    void addSum(){
        for(int i=0;i<_n;i++){
            sum += _data[i];
        }
    }
};

int CVector::sum =0;

int main(){
    int T;cin >> T;
    while(T--){
        int t;cin >> t;
        while(t--){
            int n;cin >> n;
            int* arr = new int[n];
            for(int i=0;i<n;i++){
                cin >> arr[i];
            }
            CVector(arr,n).say();
        }
        cout << CVector::sum << endl;
        CVector::sum = 0;
    }
}