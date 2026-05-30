#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>

using namespace std;
class bankacc
{
private:
    int accno;
    string name;
    double bal;

public:
    void createaccount()
    {
        cout << "enter acc no.";
        cin >> accno;
        cout << "ENter name" << endl;
        cin >> name;
        bal = 0.00;
        
    }
    double deposit(double amount)
    {
        bal += amount;
        return bal;
    }
    double withdraw(double amount)
    {
        if (bal >= amount)
        {
            bal -= amount;
        }
        return bal;
    }
    void view() {
        cout<<"balance: "<<bal<<endl;
        cout<<name;
    }

};
#endif
