#include <iostream>

using namespace std;

class ATM
{
private:
    int balance;
    int pin;
public:
    ATM()
    {
        balance = 10000;
        pin=2345;
    }
    bool verify_pin()
    {
        int p, attempts=3;
        while(attempts>0)
        {
            cout<<"\nEnter PIN here: ";
            cin>>p;
            if(p==pin)
            {
                return true;
            }
            attempts--;
            cout<<"\nWrong PIN...Attempts left: "<<attempts<<endl;
        }
        return false;

    }
    bool menu()
    {
        bool running=true;
        int op;
        while(running)
        {
            cout<<"\n1. Withdrwal";
            cout<<"\n2. Balance check";
            cout<<"\n3. Change PIN";
            cout<<"\n4. Exit";
            cout<<"\nSelect your option: ";
            cin>>op;
            switch(op)
            {
            case 1: withdraw();break;
            case 2: Balance_check();break;
            case 3:
                Change_pin();
                return true;
            case 4:
                running=false;
                cout<<"\nThankyou visit again"<<endl;
                return false;
            default:
                cout<<"\nInvalid Option...TryAgain"<<endl;
                border();
            }
        }
    }

    void withdraw()
    {
        int withdrawal_amount;
        cout<<"\nEnther withdrawal amount: ";
        cin>>withdrawal_amount;
        while(withdrawal_amount<=0 || withdrawal_amount%100!=0)
        {
            if(withdrawal_amount <= 0)
            {
                cout<<"\nEnter appropriate amount";
                cout<<"\nEnter withdrawal amount: ";
                cin>>withdrawal_amount;
            }
            else
            {
                cout<<"\nEnter amount in multiples of 100";
                cout<<"\nEnter withdrawal amount: ";
                cin>>withdrawal_amount;
            }
        }
        if(balance>withdrawal_amount)
        {
            balance-=withdrawal_amount;
            cout<<"\n Transaction is successful";
            cout<<"\nBalance: "<<balance<<endl;
            border();
        }
        else
        {
            cout<<"\nInsufficient balance";
            cout<<"\nBalance: "<<balance<<endl;
            border();
        }
    }
    void Balance_check()
    {
        cout<<"\nBalance: "<<balance<<endl;
        border();
    }
    bool Change_pin()
    {
        int newpin;
        while(true)
        {
            cout<<"\nEnter new 4-digit PIN: ";
            cin>>newpin;
            if(newpin>=1000 && newpin<=9999)
            {
                pin=newpin;
                cout<<"\nPIN changed successfully"<<endl;
                border();
                return true;
            }
            else
            {
                cout<<"\nPlease Enter Valid PIN here";
            }
        }
    }

    void border()
    {
        for(int i=0;i<50;i++)
        {
            cout<<"-";
        }
    }

};

int main()
{
    ATM atm;

    while (true)
    {
        if (!atm.verify_pin())
        {
            cout << "Card blocked. Try later.\n";
            break;
        }

        bool pinChanged = atm.menu();

        if (!pinChanged)
            break;

        cout << "\nPlease login again with new PIN\n";
    }

    return 0;
}
