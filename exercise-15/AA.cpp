#include<bits/stdc++.h>

using namespace std;

template <typename T>
int search(T* a, int len, T tar){
  for(int i=0;i<len;i++){
    if(a[i] == tar) return i+1;
  }
  return 0;
};
template <typename T>
void go (int len) {
  T* arr = new T[len];
  for (int i=0; i<len ;i++) {
    cin >> arr[i];
  }
  T tar;cin >> tar;
  cout << search<T>(arr, len, tar) << endl;
}
int main(){
  int T;cin >> T ;
  while (T--) {
    char x;int len;
    cin >> x >> len;
    switch (x)
    {
    case 'I':
      go<int>(len);
      break;
    case 'D':
      go<double>(len);
      break;
    case 'C':
      go<char>(len);
      break;
    case 'S':
      go<string>(len);
      break;
    default:
      break;
    }
  }
}