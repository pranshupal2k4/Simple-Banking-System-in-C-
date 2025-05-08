#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string fathersName;
    string aadhar;
    string accountNumber;
    string mobile;
    string address;
    string email;
    string dob;
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void createAccount() {
        cout << "Enter account holder name: ";
        getline(cin, accountHolderName);
        cout << "Enter Father's name: ";
        getline(cin, fathersName);

        cout << "Enter date of birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Enter mobile number: ";
        getline(cin, mobile);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter aadhar number: ";
        cin >> aadhar;
        cout << "Account created successfully!" << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout<<endl;
        cout << "Deposited amount is: $" << amount << endl;
        cout<< "Current balance is : $"<<balance<<endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
        	cout<<endl;
            cout << "Insufficient balance!" << endl;
            cout<< "Current balance is : $"<<balance<<endl;
        } else {
            balance -= amount;
            cout<<endl;
            cout << "Withdrawn amount is: $" << amount << endl;
            cout<< "Current balance is : $"<<balance<<endl;
        }
    }

    void checkBalance() {
    	cout<<endl;
        cout << "Current balance is : $" << balance << endl;
    }

    void displayAccountDetails() {
    	cout<<endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Father's Name: " << fathersName << endl;
        cout << "Aadhar number: " << aadhar <<endl;
        cout << "Mobile Number: " << mobile << endl;
        cout << "Address: " << address << endl;
        cout << "Email-ID: " << email << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current balance is : $" << balance << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    cout << "Welcome to our banking system!" << endl;
    account.createAccount();

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "Press 1 for Deposit" << endl;
        cout << "Press 2 for Withdraw" << endl;
        cout << "Press 3 for Check balance" << endl;
        cout << "Press 4 for Display account details" << endl;
        cout << "Press 5 for Exit" << endl<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<< endl;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Wrong input, please enter a valid number choice!!! "<<endl;
        }
        else {
            switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                 if (cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Wrong input amount , please enter a valid amount!!! ";
                }
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Wrong input amount, please enter a valid amount!!! ";
                }
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                account.displayAccountDetails();
                break;
            case 5:
            	cout<<endl<<endl<<endl;
                cout << "Exiting..." << endl;
                return 0;
            default:
            	cout<<endl;
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        
    }

    return 0;
}