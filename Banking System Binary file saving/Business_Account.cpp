#include "Business_Account.h"

Business_Account::Business_Account() : m_allowedUsers{ 0 }, m_names{" "} {
}

std::string addUser(std::string &name) {
	std::cout << "Full name of user: ";
	std::string newName{""};
	std::getline(std::cin, newName);
	return newName;
}
void printAllowedUsers(std::vector<std::string> &m_names) {

}

void setUserAmount(int &m_allowedUsers, std::vector<std::string>& m_names) {
	std::cout << "How many users for Business Account:";
	int size{};
	std::cin >> size;
	for (int i{ 0 }; i < size; i++) {
		std::string name{};
		m_names.push_back(addUser(name));
	}
}

void Business_Account::initialSetup(std::vector<std::string>& m_names) {
	Account::setFirstName();
	Account::setLastName();
	//setUserAmount(m_allowedUsers, m_names);
	//addUser(m_names);
}
