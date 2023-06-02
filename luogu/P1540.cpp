#include<bits/stdc++.h>

using namespace std;

int Hash[1001] = {0};
int main(){
    int n,memoryStorage,cnt=0;cin >> memoryStorage >> n;
    queue<int> mem;
    while(n --){
        int tem;
        cin >> tem;
        if(!Hash[tem]){
            ++cnt;
            mem.push(tem);
            Hash[tem] = 1;
            while(mem.size() > memoryStorage){
                Hash[mem.front()] = 0;
                mem.pop();
            }
        }
    }
    cout<<cnt;
}