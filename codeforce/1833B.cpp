#include<bits/stdc++.h>

using namespace std;
struct aa {
  int n;int value;
}a[200005];

int b[200005],c[200005];

bool cmp(const aa& x, const aa& y){
  return x.value < y.value;
}
int main () {
  int T; cin >> T;
  while (T--) {
    int n,k; cin >> n >> k;
    for(int i=0; i<n ;i++){
      cin >> a[i].value;
      a[i].n = i;
    }
    for(int i=0; i<n ;i++){
      cin >> b[i];
    }
    sort(a,a+n,cmp);
    sort(b,b+n);
    for(int i=0; i<n ;i++){
      c[a[i].n] = b[i];
    }
    for( int i=0; i<n ;i++){
      cout << c[i] << " ";
    }
    cout << endl;
  }
}