#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int choice;
    bankacc acc;
    admin Admin;

    int accn;

    streampos pos;
    do
    {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Display All\n";
        cout << "6. Delete account\n";
        cout << "7. ADMIN PANEL\n";
        cout << "8. EXIT\n";
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

            if (acc.findaccount(accn, pos))
            {
                if (acc.pinverifier())
                {
                    cout << "enter amount:" << endl;
                    double amount;
                    cin >> amount;
                    acc.deposit(amount);
                    acc.saveat(pos);
                    cout << "new bal:" << " " << acc.getbal() << endl;
                }
                else
                {
                    cout << "wrong pin!" << endl;
                }
            }
            else
            {
                cout << "acc not found";
            }
            break;

        case 3:
            cout << "enter acc no:" << endl;
            cin >> accn;
            if (acc.findaccount(accn, pos))
            {
                if (acc.pinverifier())
                {
                    cout << "enter ammount to be withdrawn";
                    double amount;
                    cin >> amount;
                    acc.withdraw(amount);
                    acc.saveat(pos);
                    cout << "new bal: " << acc.getbal() << endl;
                }
                else
                {
                    cout << "wrong pin" << endl;
                }
            }
            else
            {
                cout << "ACC NOT FOUND" << endl;
            }
            break;

        case 4:
            cout << "Enter acc no." << endl;
            cin >> accn;
            if (acc.findaccount(accn, pos))
            {
                if (acc.pinverifier())
                {
                    cout << acc.getbal() << endl;
                }
                else
                {
                    cout << "wrong pin" << endl;
                }
            }
            else
            {
                cout << "wrong pin" << endl;
            }
            break;

        case 5:
            acc.displayall();
            break;

        case (6):
            cout << "enter acc no. to delete" << endl;
            cin >> accn;
            acc.deleteaccount(accn);
            break;
        case (7):
            int adminchoice;
            bool go;
            if (!(Admin.isloggedin()))
            {
                go = Admin.login();
            }
            if (!(go))
            {
                break;
            }
            do
            {
                cout << "1. View All Accounts (with PINs)\n";
                cout << "2. Delete Any Account\n";
                cout << "3. Export All to CSV\n";
                cout << "4. Logout & Return\n";
                cout << "Enter choice: ";
                cin >> adminchoice;
                switch (adminchoice)
                {
                case (1):
                    Admin.admin_display();
                    break;
                case (2):
                    cout << "enter acc no. to del";
                    int accnumber;
                    cin >> accnumber;
                    Admin.admindel(accnumber);
                    break;
                case (3):
                    Admin.exporttocsv();
                    break;
                case (4):
                    Admin.logout();
                    break;
                default:
                    cout << "INVALID CHOICE!";
                }
            } while (adminchoice != 4);
            break;

        case (8):
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}