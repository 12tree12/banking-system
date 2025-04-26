#include <iostream>
#include <set>
using namespace std;

// Global unique card number generator
long long unique_number = 1000;

// Set to keep track of unique passwords
set<string> unique_passwords;

class AccountInfo {
public:
    string username = "xxx", password = "xxx", recovery_email = "xxx";
    double balance = 0;
    long long card_number = 0;

    void putting_info() {
        cout << "\n================== Create a New Account ==================\n";
        cout << "Welcome to the Encapsulation Bank! Let's set up your account.\n";
        cout << "Enter your name: ";
        cin >> username;

        bool is_unique_password = false;
        cout << "Create your password: ";
        while (!is_unique_password) {
            cin >> password;
            if (unique_passwords.find(password) == unique_passwords.end()) {
                unique_passwords.insert(password);
                cout << "Password accepted.\n";
                is_unique_password = true;
            } else {
                cout << "Password already taken, try another one: ";
            }
        }

        cout << "Enter your recovery email: ";
        cin >> recovery_email;

        card_number = unique_number++;
        cout << "===========================================================\n";
    }

    void changing_info() {
        cout << "\n================== Account Settings ==================\n";
        cout << "[1] Change Username\n";
        cout << "[2] Change Password\n";
        cout << "[3] Change Recovery Email\n";
        cout << "[x] Exit Settings\n";
        cout << "=======================================================\n";
    }

    void showing_info() {
        cout << "\n================== Account Info ==================\n";
        cout << "Name: " << username << endl;
        cout << "Card Number: " << card_number << endl;
        cout << "Password: " << password << endl;
        cout << "Balance: $" << balance << endl;
        cout << "===================================================\n";
    }

    void depositing(double amount) {
        balance += amount;
    }

    void withdrawl(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "\n[!] Insufficient balance.\n";
        }
    }
};

void show_main_menu() {
    cout << "\n================== Main Menu ==================\n";
    cout << "[1] Create a New Account\n";
    cout << "[2] View Account Info\n";
    cout << "[3] Withdraw Money\n";
    cout << "[4] Deposit Money\n";
    cout << "[5] Account Settings\n";
    cout << "[*] View All Accounts\n";
    cout << "[x] Exit\n";
    cout << "================================================\n";
}

int main() {
    char choice = '0';
    int account_count = 0;
    AccountInfo customers[100];

    while (choice != 'x') {
        show_main_menu();
        cout << "\nChoose an option: ";
        cin >> choice;
        system("cls");  // Clear the screen

        if (choice == '1') {
            customers[account_count].putting_info();
            
            string answer;
            cout << "Would you like to deposit money now? (yes/no): ";
            cin >> answer;

            if (answer == "yes") {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;
                customers[account_count].depositing(amount);
            }

            customers[account_count].showing_info();
            account_count++;
        }
        else if (choice == '2') {
            string name, password;
            long long card;
            bool found = false;

            cout << "Enter your username: ";
            cin >> name;
            cout << "Enter your card number: ";
            cin >> card;
            cout << "Enter your password: ";
            cin >> password;

            for (int i = 0; i < 100; ++i) {
                if (customers[i].username == name && 
                    customers[i].card_number == card && 
                    customers[i].password == password) {
                    
                    customers[i].showing_info();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nAccount not found.\n";
                cout << "Would you like to create a new one? (yes/no): ";
                string ans;
                cin >> ans;

                if (ans == "yes") {
                    customers[account_count].putting_info();
                    cout << "Would you like to deposit money? (yes/no): ";
                    cin >> ans;
                    if (ans == "yes") {
                        double amount;
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        customers[account_count].depositing(amount);
                    }
                    customers[account_count].showing_info();
                    account_count++;
                } else {
                    cout << "Forgot your password? (yes/no): ";
                    string forgot;
                    cin >> forgot;
                    if (forgot == "yes") {
                        cout << "Enter your recovery email: ";
                        string email;
                        cin >> email;
                        for (int i = 0; i < 100; ++i) {
                            if (customers[i].username == name && 
                                customers[i].card_number == card && 
                                customers[i].recovery_email == email) {
                                
                                cout << "Password recovery successful: " << customers[i].password << endl;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if (choice == '3') {
            string name, password;
            long long card;
            bool found = false;

            cout << "Enter your username: ";
            cin >> name;
            cout << "Enter your card number: ";
            cin >> card;
            cout << "Enter your password: ";
            cin >> password;

            for (int i = 0; i < 100; ++i) {
                if (customers[i].username == name &&
                    customers[i].card_number == card &&
                    customers[i].password == password) {
                    
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    customers[i].withdrawl(amount);
                    cout << "New balance: $" << customers[i].balance << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nAccount not found.\n";
                cout << "Would you like to create a new one? (yes/no): ";
                string ans;
                cin >> ans;
                if (ans == "yes") {
                    customers[account_count].putting_info();
                    cout << "Would you like to deposit money? (yes/no): ";
                    cin >> ans;
                    if (ans == "yes") {
                        double amount;
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        customers[account_count].depositing(amount);
                    }
                    customers[account_count].showing_info();
                    account_count++;
                }
            }
        }
        else if (choice == '4') {
            string name, password;
            long long card;
            bool found = false;

            cout << "Enter your username: ";
            cin >> name;
            cout << "Enter your card number: ";
            cin >> card;
            cout << "Enter your password: ";
            cin >> password;

            for (int i = 0; i < 100; ++i) {
                if (customers[i].username == name &&
                    customers[i].card_number == card &&
                    customers[i].password == password) {
                    
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    customers[i].depositing(amount);
                    cout << "New balance: $" << customers[i].balance << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nAccount not found.\n";
                cout << "Would you like to create a new one? (yes/no): ";
                string ans;
                cin >> ans;
                if (ans == "yes") {
                    customers[account_count].putting_info();
                    cout << "Would you like to deposit money? (yes/no): ";
                    cin >> ans;
                    if (ans == "yes") {
                        double amount;
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        customers[account_count].depositing(amount);
                    }
                    customers[account_count].showing_info();
                    account_count++;
                }
            }
        }
        else if (choice == '5') {
            string name, password;
            long long card;
            bool found = false;

            cout << "Enter your username: ";
            cin >> name;
            cout << "Enter your card number: ";
            cin >> card;
            cout << "Enter your password: ";
            cin >> password;

            for (int i = 0; i < 100; ++i) {
                if (customers[i].username == name &&
                    customers[i].card_number == card &&
                    customers[i].password == password) {
                    
                    char setting_choice = '0';
                    while (setting_choice != 'x') {
                        customers[i].changing_info();
                        cout << "Select an option to change: ";
                        cin >> setting_choice;

                        if (setting_choice == '1') {
                            cout << "Enter new username: ";
                            cin >> customers[i].username;
                        }
                        else if (setting_choice == '2') {
                            string new_password;
                            cout << "Enter new password: ";
                            bool unique_pass = false;
                            while (!unique_pass) {
                                cin >> new_password;
                                if (unique_passwords.find(new_password) == unique_passwords.end()) {
                                    unique_passwords.erase(customers[i].password);
                                    unique_passwords.insert(new_password);
                                    customers[i].password = new_password;
                                    cout << "Password updated.\n";
                                    unique_pass = true;
                                } else {
                                    cout << "Password already taken. Try another: ";
                                }
                            }
                        }
                        else if (setting_choice == '3') {
                            cout << "Enter new recovery email: ";
                            cin >> customers[i].recovery_email;
                        }
                    }
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nAccount not found.\n";
            }
        }
        else if (choice == '*') {
            cout << "\n================== All Customers ==================\n";
            for (int i = 0; i < account_count; ++i) {
                cout << "Name: " << customers[i].username
                     << " | Card: " << customers[i].card_number
                     << " | Email: " << customers[i].recovery_email
                     << endl;
            }
            cout << "====================================================\n";
        }
    }

    cout << "Goodbye!\n";
}
