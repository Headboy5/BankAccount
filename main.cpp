#include <iostream>
//#include <stdlib.h>
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
        double getBalance() const{
            return balance;
        }

		// Display account info function
        void displayAccountInfo() const{
            std::cout << "Account Holder: " << accountHolderName << std::endl;
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Sort Code: " << sortCode << std::endl;
            std::cout << "Balance: " << balance << std::endl;
		}
		// Create card function
        void createCard() const{
			std::cout << "Creating card for " << accountHolderName << std::endl;
			int cardNumber = rand() % 90000000 + 10000000; // Random 8-digit card number
			int CVV = rand() % 900 + 100; // Random 3-digit CVV
			std::string expiryDate = "12/25"; // Fixed expiry date for simplicity
			std::cout << "Card Number: " << cardNumber << std::endl;
            std::cout << "CVV: " << CVV << std::endl;
			std::cout << "Expiry Date: " << expiryDate << std::endl;
		}
		// Register address function
        void registerAddress() {
            std::cout << "Enter address: ";
            std::cin.ignore(); // Clear the input buffer
            std::getline(std::cin, Address);
            std::cout << "Address registered: " << Address << std::endl;
		}
		// Register phone number function
        void registerPhoneNumber() {
            std::string phoneNumber;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Phone number registered: " << phoneNumber << std::endl;
		}
        

};
static bool menu(BankAccount& myAccount) {
    system("cls");
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Get Balance" << std::endl;
    std::cout << "4. Display Account Info" << std::endl;
    std::cout << "5. Create Card" << std::endl;
    std::cout << "6. Register Address" << std::endl;
    std::cout << "7. Register Phone Number" << std::endl;
    std::cout << "8. Exit" << std::endl;
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        myAccount.dep();
        break;
    case 2:
        myAccount.with();
        break;
    case 3:
        std::cout << "Current Balance: " << myAccount.getBalance() << std::endl;
        break;
    case 4:
        myAccount.displayAccountInfo();
        break;
    case 5:
        myAccount.createCard();
        break;
    case 6:
        myAccount.registerAddress();
        break;
    case 7:
        myAccount.registerPhoneNumber();
        break;
    case 8:
        std::cout << "Exiting..." << std::endl;
        return true;
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
	return false;
}
int main() {
	BankAccount myAccount;

	myAccount.balance = 1000.0;
	myAccount.accountHolderName = "John Doe";
	myAccount.accountNumber = 12345678;
	myAccount.sortCode = 112233;
    
	bool exit = false;
    while (exit == false) {
        exit = menu(myAccount);
		system("pause");
	}
    return 0;
}