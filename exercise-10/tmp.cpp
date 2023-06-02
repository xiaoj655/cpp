#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class CVector
{
    int *_data;
    int _n;

public:
    CVector(int *arr, int n) : _n(n)
    {
        _data = new int[n];
        for (int i = 0; i < n; i++)
        {
            _data[i] = arr[i];
        }
    }
    CVector()
    {
        _n = 5;
        _data = new int[_n];
        for (int i = 0; i < 5; i++)
        {
            _data[i] = i;
        }
    }
    CVector(const CVector &v){
        _n=v._n;
        _data = new int[_n];
        memcpy(_data, v._data, _n*sizeof(v._data[0]));
    }
    ~CVector()
    {
        delete[] _data;
    }
    friend CVector add(const CVector v1, const CVector v2);
    void say()
    {
        for (int i = 0; i < _n - 1; i++)
        {
            cout << _data[i] << ' ';
        }
        cout << _data[_n - 1];
        cout << endl;
    }
};

CVector add(const CVector v1, const CVector v2)
{
    int *arr = new int[v1._n];
    for (int i = 0; i < v1._n; i++)
    {
        arr[i] = v1._data[i] + v2._data[i];
    }
    return CVector(arr,v1._n);
}

int main()
{
    int T;int n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int arr[2][n];
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> arr[j][i];
            }
        }
        CVector v1(arr[0], n);
        CVector v2(arr[1], n);
        v1.say();
        v2.say();
        add(v1, v2).say();
    }
}