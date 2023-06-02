#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

deque<int> dq;
int a[N];

int main(){
    int n,k;cin >> n >> k;
    for(int i = 0;i< n ;i++ ){
        cin >> a[i];
    }
    for(int i =0 ;i < n;i++ ){
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1){
        while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            cout << a[dq.front()] << ' ';
        }
    }
    cout << endl;
    while(!dq.empty()) dq.pop_back();
    for(int i =0 ;i < n;i++ ){
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1){
        while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            cout << a[dq.front()] << ' ';
        }
    }
}