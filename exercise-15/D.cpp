#include<bits/stdc++.h>

using namespace std;

template<class T>
class Matrix {
    T* array;
    T* transposed;
    int m,n;
    public:
    Matrix() = default;
    Matrix(int m,int n):m(m),n(n){
        array = new T[m * n];
        transposed = new T[n * m];
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                cin >> array[i*n+k];
            }
        }
    }
    void transpose_matrix () {
        for (int i=0; i<n ;i++) {
            for (int k=0; k<m ;k++) {
                transposed[i*m+k] = array[k*n+i];
            }
        }
    }
    void say () {
        for (int i=0; i<n ;i++) {
            for (int k=0; k<m-1; k++) {
                cout << transposed[i*m+k] << ' ';
            }
            cout << transposed[m*i+m-1] << endl;
        }
    }
};

int main(){
    int T;cin >> T;
    while (T--) {
        char type;int m,n; cin >> type >> m >> n;
        if(type == 'I'){
            Matrix<int> a(m,n);
            a.transpose_matrix();
            a.say();
        } else if(type == 'D'){
            Matrix<double> a(m,n);
            a.transpose_matrix();
            a.say();
        } else {
            Matrix<char> a(m,n);
            a.transpose_matrix();
            a.say();
        }
}
}