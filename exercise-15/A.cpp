#include<iostream>
#include<string>

using namespace std;

template<typename T>
void find(T a[], int n) {
    T x;
    cin >> x;
    for (int i = 0; i < n; i++)
        if (a[i] == x) {
            cout << i + 1 << endl;
            return;
        }
    cout << 0 << endl;
}

template<typename T>
void processQuery() {
    int n;
    cin >> n;
    T* a = new T[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    find(a, n);
    delete[] a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char ch;
        cin >> ch;
        while (ch < 'A' || ch > 'Z') cin >> ch;
        switch (ch) {
            case 'I':
                processQuery<int>();
                break;
            case 'D':
                processQuery<double>();
                break;
            case 'S':
                processQuery<string>();
                break;
            case 'C':
                processQuery<char>();
                break;
        }
    }
    return 0;
}