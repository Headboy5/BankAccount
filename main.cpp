#include <iostream>
#include <string>
#include <random>

class BankAccount {
    public:
        double balance = 0;
        std::string accountHolderName;
	    int accountNumber = 0;
	    int sortCode = 0;
		std::string Address;
        
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

		// Get balance function
        double getBalance() {
            return balance;
        }

		// Display account info function
        void displayAccountInfo() {
            std::cout << "Account Holder: " << accountHolderName << std::endl;
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Sort Code: " << sortCode << std::endl;
            std::cout << "Balance: " << balance << std::endl;
		}
		// Create card function
        void createCard() {
			std::cout << "Creating card for " << accountHolderName << std::endl;
			int cardNumber = rand() % 90000000 + 10000000; // Random 8-digit card number
			int CVV = rand() % 900 + 100; // Random 3-digit CVV
			std::string expiryDate = "12/25"; // Fixed expiry date for simplicity
		}
		// Register address function
        void registerAddress() {
            std::cout << "Enter address: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, Address);
            std::cout << "Address registered: " << Address << std::endl;
		}
        void registerPhoneNumber() {
            std::string phoneNumber;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Phone number registered: " << phoneNumber << std::endl;
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