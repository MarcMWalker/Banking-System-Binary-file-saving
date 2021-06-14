#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Business_Account.h"
#include <vector>
#include <algorithm>
#include <fstream>

char menuScreen(std::vector<Account>& accounts) {
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "MENU";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "(C = Create New Account)\n(D = Delete Account)\n(P = Print Account Details)\n(A = Add Money to Account)\n(W = Withdraw money from account)\n(E = Exit Program)\n";
	std::cout << "Accounts Online: " << accounts.size();
	char choice{};
	std::cout << "\n>>>Input Choice: ";
	std::cin >> choice;
	return toupper(choice);
}

void setAccountType(std::vector<Account>& accounts, int& accountNum) {
	Account account;
	Business_Account bAccount;
	Savings_Account sAccount;
	std::cout << "Account types >> C = Current / B = Business / S = Savings << \n";
	std::cout << "Account type: ";
	char type{};
	std::cin >> type;

	switch (type) {
	case 'C':
	case 'c':
		account = Account();
		account.initialSetup();
		account.setAccountType(account);
		account.setAccountNumber(accountNum);
		account.deposit();
		accounts.push_back(account);
		account.print();
		return;
	case 'B':
	case 'b':
		bAccount = Business_Account();
		bAccount.initialSetup();
		bAccount.setAccountType(bAccount);
		bAccount.setAccountNumber(accountNum);
		bAccount.deposit();
		accounts.push_back(bAccount);
		bAccount.print(bAccount);
		return;
	case 'S':
	case 's':
		sAccount = Savings_Account();
		sAccount.initialSetup();
		sAccount.setAccountType(sAccount);
		sAccount.setAccountNumber(accountNum);
		sAccount.deposit();
		sAccount.addInterest(sAccount);
		accounts.push_back(sAccount);
		sAccount.print(sAccount);
		return;
	default:
		return;
	}
}

void createAccount(std::vector<Account>& accounts, int& accountNum) {
	std::cout << "**Creating new account**\n";
	setAccountType(accounts, accountNum);
	accountNum = accounts.size() + 1;
}

void deleteAccount(std::vector<Account>& accounts, int& accountNum) {
	if (accounts.size() > 0) {
		std::cout << "\nInput Account Number to delete: ";
		unsigned int number = 0;
		std::cin >> number;

		for (unsigned int i{ 0 }; i < accounts.size(); i++) {
			if (accounts.at(i).getAccountNum() == number) {
				accounts.erase(accounts.begin() + i);
				accountNum = accounts.size() + 1;
				break;
			}
			else if (accounts.at(accounts.size() - 1).getAccountNum() != number || (number - 1) > accounts.size()) {
				std::cout << "*** No account with that number exists ***\n";
				break;
			}
		}
	}
	else {
		std::cout << "*** No accounts in database*** \n";
	}
}

void printAccount(std::vector<Account>& accounts, int& accountNum) {
	std::cout << "Account Number: ";
	int num{};
	std::cin >> num;
	if (num > accountNum || num <= 0) {
		std::cout << "Sorry, no account exists with that number";
	}
	else {
		for (unsigned int i{ 0 }; i < accounts.size(); ++i) {
			if (accounts.at(i).getAccountNum() == num  /*accounts.at(i).getAccountType(accounts.at(i)) == "Current"*/) {
				accounts.at(i).print();
			}
		}
	}
}

void addMoney(std::vector<Account>& accounts) {
	std::cout << "Account Number: ";
	int num{};
	std::cin >> num;

	for (unsigned int i{ 0 }; i < accounts.size(); i++) {
		if (accounts.at(i).getAccountNum() == num) {
			accounts.at(num - 1).deposit();
			accounts.at(num - 1).print();
			break;
		}
		else if (accounts.at(accounts.size() - 1).getAccountNum() != num) {
			std::cout << "Account doesnt exist\n";
			break;
		}
	}
}

void takeMoney(std::vector<Account>& accounts) {
	std::cout << "Account Number: ";
	int num{};
	std::cin >> num;

	for (unsigned int i{ 0 }; i < accounts.size(); i++) {
		if (accounts.at(i).getAccountNum() == num) {
			accounts.at(num - 1).withdraw();
			break;
		}
		else if (accounts.at(accounts.size() - 1).getAccountNum() != num) {
			std::cout << "Account doesnt exist\n";
			break;
		}
	}
}

//learn more about binary before continuing
bool addToDatabase(std::vector<Account>& accounts) {
	size_t size = accounts.size();
	std::ofstream wf("data.txt", std::ios::out | std::ios::binary);
	wf.write((char*)&size, sizeof(Account));
	wf.close();
	if (!wf.good()) {
		std::cout << "Error during writing time\n";
		return 1;
	}
	return 0;
}

void loadDatabase() {
	std::ifstream rf;
	std::string line{};
	
	rf.open("data.txt");
	if (!rf) {
		std::cerr << "Problem reading file";
		return;
	}
	rf >> line;
	std::cout << line << std::endl;
	rf.close();
}

void exitProgram(bool& end) {
	end = true;
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Leaving Program, Goodbye...";
	std::cout << "\n-----------------------------------------------\n";
}

int main() {

	std::vector<Account> accounts{};
	loadDatabase();
	bool end{};
	size_t size = accounts.size();
	int accountNum = static_cast <int> (size) + 1;

	while (!end) {
		switch (menuScreen(accounts)) {
		case 'C':
			createAccount(accounts, accountNum);
			break;
		case 'D':
			deleteAccount(accounts, accountNum);
			break;
		case 'P':
			printAccount(accounts, accountNum);
			break;
		case 'E':
			exitProgram(end);
			addToDatabase(accounts);
			break;
		case 'A':
			addMoney(accounts);
			break;
		case 'W':
			takeMoney(accounts);
			break;
		default:
			break;
		}
	}
	return 0;
}
