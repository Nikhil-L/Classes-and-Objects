
/*
It is the simple object oriented code for bank account management system and it has all its essential features
like balance enquiry, deposit, withdrawal, changing pin number or enabling net banking transactions.
It can be improved or made versatile by adding multiple objects and accounts.
*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Transactions
{
        int Pin_Number;
        float balance;
        char ph_number[10];

    public:
        void asign()
        {
            Pin_Number = 1234;
        }

        float balance_enquiry()
        {
            return balance;
        }

        void deposit(float amount)
        {
            balance = balance + amount;
        }

        void withdraw(float amount)
        {
            if(check_balance(amount))
            {
                balance = balance - amount;
            }
            else
            {
                cout << "\nYou don't have sufficient amount in your account to withdraw";
            }
        }

        int check_pin(int pin)
        {
            if(Pin_Number != pin)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        void pin_change(int pin)
        {
            Pin_Number = pin;
        }

        void mobilebanking(char number[])
        {
            int i;

            for(i = 0; i < 10; i++)
            {
                ph_number[i] = number[i];
            }
        }

        int check_balance(float amount)
        {
            if(balance - amount >= 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
};

class Transactions t;

int main()
{
    int choice, wrong_count = 0;
    float amount, balance;
    int pin, choice_2 = 1;
    char ph_no[10];

    t.asign();

    do
    {
        cout << "Banking Transactions Main Menu";
        cout << std::endl << endl;
        cout << "1. Balance Enquiry";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Pin Code Change";
        cout << "\n5. Net Banking Registration";
        cout << "\n6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice != 6)
        {
            cout << "Enter the Pin Number : ";
            cin >> pin;
        }

        else
        {
            exit(0);
        }

        if(!t.check_pin(pin)) /// check for correct pin
        {
            cout << "\nYOu have enter the wrong pin" << endl;
            cout << "Please Enter the valid pin!\n\n";
            wrong_count += 1;
        }

        if(wrong_count == 3)
        {
            cout << "\nYou have entered wrong pin three times!" << endl;
            cout << "So you cant do any transactions for 3hrs" << endl;
            exit(0);
        }


       if(t.check_pin(pin))
       {
            switch(choice)
            {
                case 1: cout << "The balance in your account is ";
                        balance = t.balance_enquiry(); /// to get balance
                        cout << balance << "\n\n\n";
                        break;

                case 2: cout << "Enter the amount you want to deposit : ";
                        cin >> amount;
                        t.deposit(amount);
                        break;

                case 3: cout << "Enter the amount you want to withdraw : ";
                        cin >> amount;
                        t.withdraw(amount);
                        break;

                case 4: cout << "Enter you new Pin Number : ";
                        cin >> pin;
                        t.pin_change(pin);
                        cout << "Your Pin Number has been changed successfully\n\n";
                        break;

                case 5: cout << "Enter your mobile number to enable Mobile Banking : ";
                        cin >> ph_no;
                        t.mobilebanking(ph_no);
                        cout << "Your new phone number is activated for net banking\n\n";
                        break;

                defaut: cout << "Do you want to continue?\n";
                        cout << "Enter 1 to continue and 2 to exit";
                        cin >> choice_2; /// for continuation of the process
                        break;
            }
       }

    }while(choice >= 1 && choice < 6 && choice_2 == 1);
    cout << "\nThank You\n";
    cout << "Visit again";
    return 0;
}
