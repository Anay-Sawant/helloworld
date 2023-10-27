#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account
{
public:
    int tac = 0;
    int accountnum = 0;
    string username[100];
    int pin[100];
    float balance[100];
    void getaccnt(int i);
    void crtaccnt();
    void restore();
    void store();
};

void Account::restore()
{
    ifstream d("Totalaccts.txt");
    char t;
    d >> t;
    d.close();
    ifstream udata("Username.txt");
    string u;
    getline(udata, u);
    udata.close();
    ifstream pdata("Pin.txt");
    string p;
    getline(pdata, p);
    pdata.close();
    ifstream bdata("Balance.txt");
    string b;
    getline(bdata, b);
    bdata.close();
    int tnew = t;
    tac = tnew;
    int n = -1;
    int m = -1;
    int k = -1;
    for (int i = 0; i < tnew; i++)
    {
        string up;
        for (int j = (n + 1); j <= u.length(); j++)
        {
            if (j == u.length() || u[j] == '|')
            {
                n = j;
                username[i] = up;
                break;
            }
            else
            {
                up += u[j];
            }
        }
    }

    for (int i = 0; i < (tnew); i++)
    {
        string pp;
        for (int j = (m + 1); j <= p.length(); j++)
        {
            if (j == p.length() || p[j] == '|')
            {

                m = j;
                pin[i] = stoi(pp);
                break;
            }
            else
            {
                pp += p[j];
            }
        }
    }

    for (int i = 0; i < (tnew); i++)
    {
        string bp;
        for (int j = (k + 1); j <= b.length(); j++)
        {

            if (j == b.length() || b[j] == '|')
            {

                k = j;
                balance[i] = stof(bp);
                break;
            }
            else
            {
                bp += b[j];
            }
        }
    }
}

void Account::store()
{
    ofstream d("Totalaccts.txt");
    d << tac;
    d.close();
    ofstream udata("Username.txt");
    for (int i = 0; i < tac; i++)
    {
        udata << username[i] << "|";
    }
    udata.close();
    ofstream pdata("Pin.txt");
    for (int i = 0; i < tac; i++)
    {
        pdata << pin[i] << "|";
    }
    udata.close();
    ofstream bdata("Balance.txt");
    for (int i = 0; i < tac; i++)
    {
        bdata << balance[i] << "|";
    }
    udata.close();
};

void Account::getaccnt(int i)
{
    string u;
    int p;
    if (i > tac)
    {
        cout << "Sorry account doesn't exist";
    }
    else
    {
        string u;
        int p;
        cout << "Enter user name" << endl;
        cin >> u;
        cout << "Enter pin" << endl;
        cin >> p;
        if (username[i] == u && pin[i] == p)
        {
                cout << "\n Welcome!" << endl;
                int m2;
                cout << "Choose:\n1 for Deposit\n2 for Withdraw\n3 for Check Balance\n4 for Transfer Money \n5 for Transaction history \n";
                cin >> m2;
                switch (m2)
                {
                case 1:
                {
                    float am;
                    cout << "Please enter the amount";
                    cin >> am;
                    balance[i] += am;
                    cout << "Rs." << am << " has been deposited to your account.\n";
                    cout << "Final Balance is " << balance[i] << "\n";
                    string tname = "tr" + to_string(i);
                    ofstream trcn1(tname, ios::app);
                    trcn1 << "|"
                          << "Deposit " << am << " Balance " << balance[i] << "| \n";
                    trcn1.close();
                    break;
                }
                case 2:
                {
                    float am;
                    cout << "Please enter the amount";
                    cin >> am;
                    if (am < balance[i])
                    {
                        balance[i] -= am;
                        cout << "Rs." << am << " has been withdrawn from your account.\n";
                        cout << "Final Balance is " << balance[i] << "\n";
                        string tname = "tr" + to_string(i);
                        ofstream trcn1(tname, ios::app);
                        trcn1 << "|"
                              << "Withdraw " << am << " Balance " << balance[i] << "| \n";
                        trcn1.close();
                        break;
                    }
                    else
                    {
                        cout << "INSUFFICIENT BALANCE";
                        break;
                    }
                }
                case 3:
                    cout << "Your balance is " << balance[i] << endl;
                    break;
                case 4:
                    int i2;
                    cout << "Please enter the account number to transfer to: ";
                    cin >> i2;
                    if (i2 > tac || i == i2)
                    {
                        cout << "Please enter a valid account number \n";
                        break;
                    }
                    else
                    {
                        float am;
                        cout << "Please enter the amount to be transferred: ";
                        cin >> am;
                        balance[i] -= am;
                        balance[i2] += am;
                        string tname1 = "tr" + to_string(i);
                        ofstream trcn1(tname1, ios::app);
                        trcn1 << "|"
                              << "Transferred to "<< i2 << " Rs."<< am << " Balance " << balance[i] << "| \n";
                        trcn1.close();
                        string tname2 = "tr" + to_string(i2);
                        ofstream trcn2(tname2, ios::app);
                        trcn2 << "|"
                              << "Transfer received from " << i << " Rs."<< am << " Balance " << balance[i2] << "| \n";
                        trcn2.close();
                        break;
                        cout << "Amount transferred successfully.\n";
                    }
                    break;
                case 5:
                    string tname = "tr" + to_string(i);
                    ifstream trcn1(tname);
                    string out1;
                    while (getline(trcn1, out1))
                    {
                        cout << out1;
                    }
                    break;
                }  
        }
        else
        {
            cout << "Please enter correct username or password";
        }
    }
}

void Account::crtaccnt()
{
    string u;
    int p;
    tac += 1;
    cout << "Enter user name" << endl;
    cin >> u;
    cout << "Enter pin" << endl;
    cin >> p;
    if (p > 1000 && p < 9999)
    {
        username[(tac-1)] = u;
        pin[(tac-1)] = p;
        balance[(tac-1)] = 0;
        cout << "Your account has been created. Your account number is " << (tac-1);
    }
    else
    {
        cout << "Please enter valid 4 digit pin from 1000 to 9999";
    }
}

int main()
{
    Account a;
    a.restore();
    int lp = 0;
    while (true)
    {
        if (lp == 1)
        {
            a.store();
            break;
        }
        int j;
        cout << "\nWelcome! Enter:\n1 for Creating Account\n2 for Existing Account\n3 for EXIT\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.crtaccnt();
            break;
        case 2:
            cout << "Please enter your account number \n";
            cin >> j;
            a.getaccnt(j);
           
            break;

        case 3:
            lp = 1;
            break;
        }
    }

    return 0;
}