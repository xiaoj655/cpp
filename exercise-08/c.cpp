#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

int aa() {
    int a[5] = {1, 2, 3, 4, 5};
    int x = a[5]; // undefined behavior
    return 0;
}
int x = aa();

class CTelNumber{
    char* number_ = new char[100];
    bool efectiveness(){
        if (std::strlen(number_) > 7) return false;
        for(int i=0;i<7;i++){
            if(number_[i] <= '9' && number_[i] >= '0') continue;
            else return false;
        }
        return true;
    }
    public:
    CTelNumber(char* number):number_(number){}
    CTelNumber(CTelNumber& old){
        // number_ = new char[std::strlen(old.number_)+1];
        if(old.efectiveness()){
            switch (old.number_[0])
            {
            case '2': case '3' : case '4' :
                number_[0] = '8';
                break;
            case '5': case '6': case '7': case '8':
                number_[0] = '2';
                break;
            default:
                goto here;
                break;
            }
            for(int i=1;i<8;i++){
                number_[i] = old.number_[i-1];
            }
            number_[8] = '\0';
            myPrint();
        }else {
            here: cout << "Illegal phone number" << endl ;
        }
    }
    ~CTelNumber(){
        cout<< &number_ << endl;
        delete[] number_;
        // number_ = nullptr;
    }
    void myPrint(void){cout<<number_<<endl;}
};

int main(){
    int T;cin >> T;
    char* num = new char[10];
    while(T--){
        cin >> num;
        CTelNumber old(num);
        CTelNumber myNew(old);
    }
}