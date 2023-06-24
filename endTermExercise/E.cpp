#include<bits/stdc++.h>

using namespace std;

class book {
    string author,title,publisher;
    double price;
    public:
    book() = default;

    book(string author, string title, string publisher, double price):\
    author(author),title(title),publisher(publisher),price(price){}

    friend void find(book*, int n,int& max1Index,int& max2Index);

    void say () {
        cout << title << '\n';
        cout << author << '\n';
        cout << fixed << setprecision(2) << price << '\n';
        cout << publisher << '\n';
        cout << endl;
    }

};

void find(book* books,int n,int& max1Index,int& max2Index){
    // for (int i=1;i<n;i++) {
    //     if (books[i].price > books[max2Index].price) {
    //         max2Index = i;
    //     }
    //     if (books[i].price > books[max1Index].price) {
    //         max2Index = max1Index;
    //         max1Index = i;
    //     }
    //     if (books[max2Index].price > books[max2Index].price) swap(max1Index,max2Index);
    // }
    sort(books,books+n,[](book& a,book& b) {
        return a.price > b.price;
        });
}

int main () {
    int T;cin >> T;
    while (T--) {
        int n;cin >> n;
        book* books = new book[n];
        // getchar();
        // for (int i=0;i<n;i++) {
        //     string data;
        //     getline(cin,data);
        //     size_t start=0, end=0;
        //     vector<string> refer;
        //     while ((end=data.find(',',start)) != string::npos) {
        //         refer.push_back(data.substr(start,end-start));
        //         start = end+1;
        //     }
        //     refer.push_back(data.substr(start));
        //     books[i] = book(refer[1],refer[0],refer[3],stod(refer[2]));
        //     refer.clear();
        // }
        for (int i=0;i<n;i++) {
            string author,title,publisher;
            string price;
            getline(cin, title,',');
            getline(cin, author,',');
            getline(cin, price,',');
            getline(cin, publisher,'\n');
            books[i] = book(author,title,publisher,stod(price));
        }

        int max1Index=0,max2Index=1;

        find(books,n,max1Index,max2Index);

        books[0].say();
        books[1].say();

        delete[] books;
    }
}