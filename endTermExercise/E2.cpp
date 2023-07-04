#include<bits/stdc++.h>

using namespace std;

class CBook {
    string title,author,publisher;
    double price;
    public:
    CBook() = default;
    CBook(istream& cin){
        string title,author,publisher;
        string price;
        getline(cin,title,',');
        getline(cin,author,',');
        getline(cin,price,',');
        getline(cin,publisher);
        this->title = title;
        this->author=author;
        this->price = stod(price);
        this->publisher = publisher;
    }
    void say() {
        cout << title << endl;
        cout << author << endl;
        cout << fixed <<setprecision(2) << price << endl;
        cout << publisher << endl;
        cout << '\n';
    }
    friend void find(CBook*,int,int&,int&);
    double get_price(){
        return price;
    }
};
void find(CBook* a,int n, int& max1index,int& max2index) {
    for (int i=0;i<n;i++) {
        if(a[max2index].price < a[i].price) {
            max2index = i;
        }
        if(a[max1index].price < a[max2index].price){
            swap(max1index,max2index);
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--) {
        int n;cin >> n;
        CBook* a = new CBook[n];
        for(int i=0;i<n;i++){
            a[i] = CBook(cin);
        }
        int max1index = 0;
        int max2index = 1;
        if (a[0].get_price() < a[1].get_price()) swap(max1index,max2index);
        find(a,n,max1index,max2index);
        a[max1index].say();
        a[max2index].say();
    }
}
