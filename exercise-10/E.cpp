#include<iostream>
#include<cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

class CMatrix;

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
    friend class CMatrix;
};

class CMatrix{
    int _n;int** _data;
    public:
    CMatrix(){
        int i, j;
        cin >> _n;
        // 先创建n行
        _data = new int* [_n];
        // 再创建n列
        for (i = 0; i < _n; i++)
        {
            _data[i] = new int[_n];
        }
        // 写入矩阵
        for (i = 0; i < _n; i++)
        {
            for (j = 0; j < _n; j++)
            {
                cin >> _data[i][j];
            }

}
    }
    bool access(CVector& v){
        return v._n == _n ;
    }
    CVector multi(const CVector &v1){
        int* arr = new int[v1._n];
        for(int i=0;i<v1._n;i++){
            arr[i] = 0;
            for(int j=0;j<v1._n;j++){
                arr[i] += _data[i][j] * v1._data[j];
            } 
        }
        return CVector(arr,v1._n);
    }
};

int main(){
    int T;cin >>T;
    while(T--){
        CMatrix m;
        int n;cin >> n;int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        CVector v(arr,n);
        if(m.access(v)){
            m.multi(v).say();
        }else{
            cout << "error" <<endl;
        }
    }
}