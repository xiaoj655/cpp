#include<iostream>
#include<cstring>
#include<iomanip>


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
        float sum =0;
        for(int i=0;i<_n ;i++){
            cout << _data[i] << ' ' ;
            sum += _data[i];
        }
        cout << std::fixed<<std::setprecision(2)<< sum/_n;
        cout << endl;
    }
};

class CStudent{
    string _name;
    CVector _score;
    public:
    CStudent(){}
    CStudent(string name,int n ,int* arr):_name(name),_score(arr,n){}
    void say(){
        cout<<_name<<' ';
        _score.say();
    }
};


int main(){
    string name;int n;
    while(cin >> name){
        cin >> n;int* arr = new int[n];
        for(int i=0;i< n;i++){
            cin >> arr[i];
        }
        CStudent(name,n,arr).say();
    }
}