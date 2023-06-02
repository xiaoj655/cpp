#include <iostream>
#include <string>

using namespace std;


class Member {
protected:
    int id; 
    int travelPoints; 
public:
    Member() : travelPoints(0) {}
    Member(int id) : id(id), travelPoints(0) {}
};


class CreditCard {
protected:
    int id; 
    int creditLimit; 
    int cardPoints; 
    string name; 
    float billAmount; 
public:
    CreditCard() : billAmount(0), cardPoints(0) {}
    CreditCard(int id, string name, int creditLimit)
        : id(id), name(name), creditLimit(creditLimit), cardPoints(0) {}
};


class VIPCreditCard : public Member, public CreditCard {
public:
    VIPCreditCard(int memberId, int cardId, string name, int creditLimit)
        : Member(memberId), CreditCard(cardId, name, creditLimit    ) {}

    
    void refund(float amount) {
        if (amount <= billAmount) {
            billAmount -= amount;
            cardPoints -= static_cast<int>(amount);
        }
    }

    
    void placeOrder(float amount) {
        travelPoints += static_cast<int>(amount);
        cardPoints += static_cast<int>(amount);
        billAmount += amount;
    }

    
    void makePurchase(float amount) {
        if (billAmount + amount <= creditLimit) {
            billAmount += amount;
            cardPoints += static_cast<int>(amount);
        }
    }

    
    void exchangePoints(float amount) {
        if (amount <= cardPoints) {
            cardPoints -= static_cast<int>(amount);
            travelPoints += static_cast<int>(amount) / 2;
        }
    }

    
    void display() {
        cout << id << " " << travelPoints << endl;
        cout << id << " " << name << " " << billAmount << " " << cardPoints << endl;
    }
};

int main() {
    int memberId, cardId, creditLimit, numCommands;
    string name, command;
     
    cin >> memberId >> cardId >> name >> creditLimit >> numCommands;
    VIPCreditCard vipCard(memberId, cardId, name, creditLimit);

    while (numCommands--) {
        float amount;
        cin >> command >> amount;

        if (command == "o")
            vipCard.placeOrder(amount);
        else if (command == "c")
            vipCard.makePurchase(amount);
        else if (command == "q")
            vipCard.refund(amount);
        else if (command == "t")
            vipCard.exchangePoints(amount);
    }

    vipCard.display();
    return 0;
}