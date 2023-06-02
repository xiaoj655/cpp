#include<bits/stdc++.h>

using namespace std;

int main(){
    list<int> node;
    for(int i =1 ;i< 5;i++){
        node.push_back(i);
    }
    auto iter = node.begin();
    for(int i =1;i<5;i++){
        if(++iter == node.end()){
            iter = node.begin();
            cout << "here" << *iter; 
        }
    }
}