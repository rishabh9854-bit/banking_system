#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
const string admin_name = "admin";
const string admin_pass = "admin123";
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
        cout << "enter name" << endl;
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
        cout << endl;
        while (in.read(reinterpret_cast<char *>(this), sizeof(bankacc)))
        {
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
            out.write(reinterpret_cast<char *>(this), sizeof(bankacc));
        }
        out.close();
        in.close();
        remove(filename);
        rename("temp.dat", filename);
        if (found)
        {
            cout << "removed" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }
};
class admin
{
private:
    bool loggedin = false;
    bankacc helper;

public:
    bool login()
    {
        string user, pass;
        cout << "ENTER ADMIN USERNAME " << endl;
        cin >> user;
        cout<<"enter pass ";
        cin >> pass;
        if (user == admin_name && pass == admin_pass)
        {
            loggedin = true;
            return true;
        }
        else
        {
            cout << "invalid credentials";
            return false;
        }
        return false;
    }
    void logout()
    {
        loggedin = false;
        cout << "logged out" << endl;
    }
    void admindel(int searchacc)
    {
        if (!loggedin)
        {
            cout << "invalid creds!" << endl;
            return;
        }
        helper.deleteaccount(searchacc);
    }
    bool isloggedin()
    {
        return loggedin;
    }
    void admin_display()
    {
        if (!loggedin)
        {
            return;
        }
        ifstream in("accounts.dat", ios::binary);
        if (!in)
        {
            cout << "empty file" << endl;
            return;
        }
        cout << "\n"
             << left << setw(12) << "ACCNO " << setw(25) << "NAME" << setw(12) << "BALANCE" << setw(10) << "PIN" << "\n";
        cout << string(59, '-') << endl;
        bankacc tmp;
        while (in.read(reinterpret_cast<char *>(&tmp), sizeof(bankacc)))
        {
            cout << left << setw(12) << tmp.getaccno() << setw(25) << tmp.getname() << setw(12) << fixed << setprecision(2) << tmp.getbal() << setw(10) << tmp.getpin() << "\n";
        }
        in.close();
    }
    void exporttocsv(const string &filename = "accountsdata.csv")
    {
        if (!loggedin)
        {
            return;
        }
        ifstream in("accounts.dat", ios::binary);
        ofstream csv(filename);
        if (!in)
        {
            cout << "no data found~" << endl;
            return;
        }
        csv << "ACC NO,NAME,BAL,PIN\n";
        bankacc temp;
        int count = 0;
        while (in.read(reinterpret_cast<char *>(&temp), sizeof(bankacc)))
        {
            count++;
            csv << temp.getaccno() << ","<< temp.getname() << "," <<fixed << setprecision(2) << temp.getbal() << "," << temp.getpin() << "\n";
        }
        in.close();
        csv.close();
        cout << count << " record(s) exported to \"" << filename << "\".\n";
    }
};
#endif
