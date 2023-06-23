#include<bits/stdc++.h>

using namespace std;

template<class T>
class List {
    T arr[100];
    int effective_length;
    public:
    List() = default;
    List(int len):effective_length(len){
        for(int i=0;i<100;i++) arr[i]=0;
        for(int i=0;i<len;i++){
            cin >> arr[i];
        }
    }
    void insert() {
        int index;T val;
        cin >> index >> val;
        for (int i=effective_length-1;i>=index;i--)
        arr[i+1] = arr[i];
        arr[index] = val;
        ++effective_length;
    }
    void del() {
        int index;
        cin >> index;
        for (int i=index;i<effective_length-1;i++) {
            arr[i] = arr[i+1];
        }
        --effective_length;
    }
    void say() {
        for (int i=0;i<effective_length-1;i++)
        cout << arr[i] << ' ';
        cout << arr[effective_length-1] << endl;
    }

};

int main(){
    int len;cin >> len;
    List<int> a(len);
    a.insert();
    a.del();
    a.say();
    cin >> len;
    List<double> b(len);
    b.insert();
    b.del();
    b.say();
}