#include<bits/stdc++.h>

using namespace std;
int md1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int md2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int sum1[13],sum2[13];
int run (int x) {
	if(x%4==0&&x%100!=0 || x%400==0) return 1;
	return 0;
}
int cal(int* end){
  int start[3] = {0,1,1};
	int res=0;
	for(int i=start[0]; i<end[0] ;i++){
		if (run(i)) res += 366;
		else res += 365;
	}
	if(run(end[0])){
		res += sum2[end[1]-1] - sum2[start[1]-1];
	} else {
		res += sum1[end[1]-1] - sum1[start[1]-1];
	}
	res += end[2] - start[2];
	return res;
}

int main () {
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  cout << cal(arr);
}