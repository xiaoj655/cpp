#include<bits/stdc++.h>

using namespace std;

int cnt=0;

template<typename T>
struct score {
    T id;
    int score;
};

template<class T>
void process(score<T>* scores){
    T tar;cin >> tar;
    bool flag=false;
    for(int i=0;i<cnt;i++){
        if(scores[i].id == tar){
            flag=true;
            scores[i].score++;
            break;
        }
    }
    if(!flag){
        scores[cnt].id = tar;
        scores[cnt].score = 1;
        cnt++;
    }
}
template<class T>
int max(score<T>* a, int len){
    int max=0;
    for (int i=1;i<len;i++) {
        if (a[i].score > a[max].score) max = i;
    }
    return max;
}

int main(){
  int n;cin >> n;
  while(n--){
    char type;int len;
    cin >> type >> len;
    if (type == 'I') {
        struct score<int>* scores = new score<int>[len];
        for (int i=0;i<len;i++){
            process(scores);
        }
        cnt=0;
        int maxId = max(scores,len);
        cout << scores[maxId].id << ' ' << scores[maxId].score << endl;
    } else if (type == 'C') {
        struct score<char>* scores = new score<char>[len];
        for (int i=0;i<len;i++){
            process(scores);
        }
        cnt=0;
        int maxId = max(scores,len);
        cout << scores[maxId].id << ' ' << scores[maxId].score << endl;
    } else if (type == 'S') {
        struct score<string>* scores = new score<string>[len];
        for (int i=0;i<len;i++){
            process(scores);
        }
        cnt=0;
        int maxId = max(scores,len);
        cout << scores[maxId].id << ' ' << scores[maxId].score << endl;
    }
  }  
}