#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int choice;
    bankacc acc;
    int pin;
    int accn;
    double amount;
    do
    {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            acc.createaccount();
            break;

        case 2:
            int pin;
            int accn;
            cout << "enter acc no." << endl;
            cin >> accn;

            cout << "enter pin: " << endl;
            cin >> pin;

            cout << "Enter amount: ";
            cin >> amount;
            acc.deposit(amount);
            break;

        case 3:
            cout << "enter acc no." << endl;
            cin >> accn;

            cout << "enter pin: " << endl;
            cin >> pin;
            cout << "Enter amount: ";
            cin >> amount;
            acc.withdraw(amount);
            break;

        case 4:
            cout << "enter acc no." << endl;
            cin >> accn;

            cout << "enter pin: " << endl;
            cin >> pin;
            acc.view();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}