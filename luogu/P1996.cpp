#include<bits/stdc++.h>
using namespace std;
// struct node {
//     int data;
//     node *next;
// };

// int main(){
//     int account,n;scanf("%d%d",&account,&n);
//     node* now,*p, *head, *prev;
//     head = new node ;
//     head->data = 1;
//     head->next = nullptr;
//     now = head;
//     for(int i =2 ;i<=account;i++){
//         p = new node;
//         p->data = i;
//         now->next=p;
//         p->next = nullptr;
//         now = p;
//     }
//     now->next=head;
//     now= head;
//     prev = head;

//     while((account--) > 1){
//         for(int i=1;i<n;i++){
//             prev = now;
//             now = now->next;
//         }
//         printf("%d ",now->data);
//         prev->next = now->next;
//         delete now;
//         now = prev->next;
//     }
//     printf("%d",now->data);
//     delete now;
//     return 0;
// }

int main(){
    list<int> node;
    int account,n;cin >> account >> n;
    for(int i = 1;i<= account;i++){
        node.push_back(2*i);
    }
    auto it = node.begin();
    while(node.size() > 1){
        for(int i =1 ;i<n;++i){
            if(++it == node.end()){ 
                it = node.begin();}
            }
        auto tmp = ++it;
        if(tmp == node.end()) tmp = node.begin();
        node.erase(--it);
        it = tmp;
    }
    cout << *it;
}