#include<bits/stdc++.h>
using namespace std;

int arr[200005];

int main () {
  int T; cin >> T;
  while(T--) {
    int n,tem=0x7fffffff,flag=1,flag2=0; cin >> n;
    for(int i =0 ;i<n;i++){
      cin >> arr[i];
      if(tem > arr[i] && arr[i]%2 !=0){
        tem = arr[i];
        flag2=1;
      }
    }
    if(flag2){
    for(int i=0;i<n;i++){
      if(arr[i]%2 != 0) continue;
      if(tem > arr[i]){
        flag=0;
        break;
      }
    }}
    if(flag) cout << "YES"<< endl;
    else cout << "NO" << endl;
  }
}