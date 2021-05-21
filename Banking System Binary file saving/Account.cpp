#include "Account.h"

bool Account::withdraw() {
	if (m_moneyInAccount <= 0) {
		std::cout << "Sorry you have no money left to withdraw!\n";
		return false;
	}
	else {
		bool correct{};
		while (correct != true) {
			std::cout << "Withdraw amount: ";
			double val{};
			std::cin >> val;

			if ((m_moneyInAccount - val) < 0) {
				std::cout << "Sorry this is over your account limit\n";
			}

			else {
				m_moneyInAccount -= val;
				correct = true;
			}
		}
		print();
		return true;
	}
}

void Account::deposit() {
	std::cout << "Deposit amount: ";
	double val{};
	std::cin >> val;
	m_moneyInAccount += val;
	print();
}

void Account::setFirstName() {
	std::cout << "First name: ";
	std::string name{};
	std::cin >> name;
	m_firstName = name;
}

void Account::print() {
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "ACCOUNT DETAILS";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Name: " << m_firstName << " " << m_lastName;
	std::cout << "\nMoney: " << "$" << m_moneyInAccount;
	std::cout << "\nAccount type: " << m_accountType;
	std::cout << "\nAccount Number: " << m_accountNumber;
}

void Account::setAccountType() {
	std::cout << "Account types >> C = Current / B = Business / S = Savings << \n";
	std::cout << "Account type: ";
	char type{};
	std::cin >> type;

	switch (type) {
	case 'c':
	case 'C':
		m_accountType = "Current";
		break;
	case 'b':
	case 'B':
		m_accountType = "Business";
		break;
	case 's':
	case 'S':
		m_accountType = "Savings";
		break;
	default:
		break;
	}
}

void Account::initialSetup() {
	setFirstName();
	setLastName();
	setAccountType();
}

void Account::setAccountNumber(int num) {
	m_accountNumber = num;
}

int Account::getAccountNum() {
	return m_accountNumber;
}

Account::~Account()
{
}

void Account::setLastName() {
	std::cout << "Last name: ";
	std::string name{};
	std::cin >> name;
	m_lastName = name;
}
