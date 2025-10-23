#include <iostream>
#include <string>

class BankAccount {
    public:
        double balance = 0;
        std::string accountHolderName;
	    int accountNumber = 0;
	    int sortCode = 0;
        
		// Deposit function
        void dep() {
            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            balance += amount;
            std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
        }

		// Withdraw function
        void with() {
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (amount > balance) {
                std::cout << "Insufficient funds!" << std::endl;
            }
            else {
                balance -= amount;
            }
            std::cout << "Withdrawing: " << amount << ", New Balance " << balance << std::endl;
        }          
};

int main() {
	BankAccount myAccount;

	myAccount.balance = 1000.0;
	myAccount.accountHolderName = "John Doe";
	myAccount.accountNumber = 12345678;
	myAccount.sortCode = 112233;
    myAccount.dep();
	myAccount.with();

    return 0;
}