#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
class bankacc
{
private:
    int accno;
    char name[50];
    double bal;
    int pin;
    const char *filename = "accounts.dat";

public:
    void createaccount()
    {
        cout << "enter acc no.";
        cin >> accno;
        cin.ignore();           
        cin.getline(name, 50);
        cout << "enter pin: ";
        cin >> pin;
        cout << "enter balance: ";
        cin >> bal;
        ofstream out(filename, ios::binary | ios::app);
        out.write(reinterpret_cast<char *>(this), sizeof(bankacc));
        out.close();
        cout << "account created successfully!" << endl;
    }
    // getter functions
    int getaccno()
    {
        return accno;
    }
    int getbal()
    {
        return bal;
    }
    int getpin()
    {
        return pin;
    }
    const char *getname()
    {
        return name;
    }
    bool pinverifier()
    {
        int p;
        cout << "enter pin: " << endl;
        cin >> p;
        return p == pin;
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
            return bal;
        }

        else
        {
            cout << "insufficient balance!!!" << endl;
        }
        return bal;
    }
    void view()
    {
        cout << left << setw(10) << accno << setw(25) << name << setw(10) << bal << "\n";
    }
    bool findaccount(int searchacc, streampos &pos)
    {
        ifstream in(filename, ios::binary);
        while (in.read(reinterpret_cast<char *>(this), sizeof(bankacc)))
        {
            if (accno == searchacc)
            {
                pos = in.tellg() - (streampos)sizeof(bankacc);
                in.close();
                return true;
            }
        }
        in.close();
        return false;
    }
    void saveat(streampos pos)
    {
        fstream file(filename, ios::binary | ios::in | ios::out);
        file.seekp(pos);
        file.write(reinterpret_cast<char *>(this), sizeof(bankacc));
        file.close();
    }
    void displayall()
    {
        ifstream in(filename, ios::binary);
        cout << left << setw(10) << "AccNo"
             << setw(25) << "Name"
             << setw(10) << "Balance" << "\n";
        cout<<endl;
        while (in.read(reinterpret_cast<char*>(this), sizeof(bankacc))) {
            view();
        }
        in.close();
    }
    void deleteaccount(int searchacc)
    {
        ifstream in(filename, ios::binary);
        ofstream out("temp.dat", ios::binary);
        bool found = false;
        while (in.read(reinterpret_cast<char *>(this), sizeof(bankacc)))
        {
            if (searchacc = accno)
            {
                found = true;
                continue;
            }
            out.write(reinterpret_cast<char*>(this),sizeof(bankacc));
        }
        out.close();
        in.close();
        remove (filename);
        rename("temp.dat",filename);
        if(found){
            cout<<"removed"<<endl;

        }
        else{
            cout<<"not found"<<endl;
        }
    }
};
#endif
