#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int choice;
    bankacc acc;
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
            cout << "Enter amount: ";
            cin >> amount;
            acc.deposit(amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            acc.withdraw(amount);
            break;

        case 4:
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