#include "Business_Account.h"

Business_Account::Business_Account() : m_allowedUsers{ 0 }, m_names{}, m_accountType{""} {
}

std::string Business_Account::addUser(std::string &name) {
	std::cout << "Full name of user: ";
	std::string newName{""};
	std::getline(std::cin, newName);
	return newName;
}
void Business_Account::printAllowedUsers(std::vector<std::string> &m_names)const {
	for (auto i : m_names) {
		std::cout << i << "\n";
	}
}

void Business_Account::setUserAmount(int &m_allowedUsers, std::vector<std::string>& m_names) {
	std::cout << "How many users for Business Account: ";
	int size{};
	std::cin >> size;
	for (int i{ 0 }; i < size; i++) {
		std::string name{};
		std::cout << "Name of user #" << i+1 << ">>> ";
		std::cin >> name;
		m_names.push_back(name);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

void Business_Account::initialSetup() {
	Account::setFirstName();
	Account::setLastName();
	setUserAmount(m_allowedUsers, m_names);
}

void Account::getAccountType(Account& account) {
	account.m_accountType;
}

void Business_Account::setAccountType(Account& account){
	m_accountType = "Business";
}

void Business_Account::print(Business_Account &account)const {
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "ACCOUNT DETAILS";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Account Owner: " << Account::printName();
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Allowed users: \n"; 
	printAllowedUsers(account.m_names);
	std::cout << "-----------------------------------------------\n";
	std::cout << "Money: " << "$" << Account::getMoneyInAccount();
	std::cout << "\nAccount type: " << m_accountType;
}
