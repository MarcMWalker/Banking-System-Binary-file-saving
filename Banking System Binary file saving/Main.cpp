#include <iostream>
#include "Account.h"
#include <vector>
#include <algorithm>
#include <fstream>

char menuScreen(std::vector<Account>& accounts) {
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "MENU";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "(C = Create New Account)\n(D = Delete Account)\n(P = Print Account Details)\n(A = Add Money to Account)\n(E = Exit Program)\n";
	std::cout << "Accounts Online: " << accounts.size();
	char choice{};
	std::cout << "\n>>>Input Choice: ";
	std::cin >> choice;
	return toupper(choice);
}

void createAccount(std::vector<Account>& accounts, int& accountNum) {
	Account account;
	std::cout << "**Creating new account**\n";
	account = Account();
	account.initialSetup();
	account.setAccountNumber(accountNum);
	accounts.push_back(account);
	accountNum = accounts.size() + 1;
	account.print();
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
			if (accounts.at(i).getAccountNum() == num) {
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
	std::ofstream wf("data.dat", std::ios::out | std::ios::binary);
	wf.write((char*)&size, sizeof(Account));
	wf.close();
	if (!wf.good()) {
		std::cout << "Error during writing time\n";
		return 1;
	}
	return 0;
}

void loadDatabase(std::vector<Account>& accounts) {
	std::ifstream rf("data.dat", std::ios::out | std::ios::binary);
	int size = rf.tellg() / sizeof(Account);
	Account temp[20];

	rf.seekg(std::ifstream::end);
	rf.read((char*)&temp, sizeof(temp));
	/*for (int i{ 0 }; i < 100; ++i) {
	accounts.push_back(temp[i]);
	}*/
	rf.close();
}

void exitProgram(bool& end) {
	end = true;
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Leaving Program, Goodbye...";
	std::cout << "\n-----------------------------------------------\n";
}

int main() {
	//Guess I have to upload binary data somewhere to include past data
	std::ifstream indata;
	indata.open("data.dat");

	std::vector<Account> accounts{};
	//loadDatabase(accounts);
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
		default:
			break;
		}
	}
	indata.close();
	return 0;
}
