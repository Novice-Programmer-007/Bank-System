#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int accNo;
};

class BankAccount {
private:
    Customer cust;
    float balance;

    static int totalAccounts;
    static float totalBankBalance;

public:
    BankAccount() {
        cust.name = "N/A";
        cust.accNo = 0;
        balance = 0.0;
    }

    void createAccount(const string& n, int a, float b) {
        cust.name = n;
        cust.accNo = a;
        balance = b;
        totalAccounts++;

        totalBankBalance += b;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            totalBankBalance += amount;
            cout << "Deposited Rs." << amount << " successfully.\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            totalBankBalance -= amount;
            cout << "Withdrawn Rs." << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void displayDetails() const {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << cust.name << endl;
        cout << "Account Number: " << cust.accNo << endl;
        cout << "Current Balance: Rs." << balance << endl;
    }

    int getAccountNo() const {
        return cust.accNo;
    }

    static void showBankSummary() {
        cout << "\n--- Bank Summary ---";
        cout << "\nTotal Accounts: " << totalAccounts;
        cout << "\nTotal Balance in Bank: Rs." << totalBankBalance << endl;
    }
};

int BankAccount::totalAccounts = 0;
float BankAccount::totalBankBalance = 0.0;

int main() {
    const int MAX = 5;
    BankAccount accounts[MAX];
    int accountCount = 0;
    int choice;

    cout << "===============================\n";
    cout << "    BANK MANAGEMENT SYSTEM\n";
    cout << "===============================\n";

    do {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Show Bank Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (accountCount < MAX) {
                string name;
                int accNo;
                float initialBalance;

                cin.ignore();
                cout << "\nEnter Customer Name: ";
                getline(cin, name);
                cout << "Enter Account Number: ";
                cin >> accNo;
                cout << "Enter Initial Deposit: Rs.";
                cin >> initialBalance;

                accounts[accountCount].createAccount(name, accNo, initialBalance);
                accountCount++;
                cout << "Account created successfully!\n";
            } else {
                cout << "Cannot create more accounts (limit reached)!\n";
            }
        }

        else if (choice == 2) {
            int accNo;
            float amount;
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].getAccountNo() == accNo) {
                    cout << "Enter amount to deposit: Rs.";
                    cin >> amount;
                    accounts[i].deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found!\n";
        }

        else if (choice == 3) {
            int accNo;
            float amount;
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].getAccountNo() == accNo) {
                    cout << "Enter amount to withdraw: Rs.";
                    cin >> amount;
                    accounts[i].withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found!\n";
        }

        else if (choice == 4) {
            int accNo;
            cout << "\nEnter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i].getAccountNo() == accNo) {
                    accounts[i].displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found!\n";
        }

        else if (choice == 5) {
            BankAccount::showBankSummary();
        }

        else if (choice == 6) {
            cout << "\nThank you for using Bank Management System!\n";
        }

        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
