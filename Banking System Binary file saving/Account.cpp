#include "Account.h"
int::Account::m_AccountTotals{0};

Account::Account()
	: m_firstName{ "" }, m_lastName{ "" }, m_accountType{ "" }, m_moneyInAccount{ 0.00 }, m_accountNumber{ 0 } {
	++m_AccountTotals;
}

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
}

void Account::setFirstName() {
	std::cout << "First name: ";
	std::string name{};
	std::cin >> name;
	m_firstName = name;
}

void Account::print()const {
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "ACCOUNT DETAILS";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Name: " << m_firstName << " " << m_lastName;
	std::cout << "\nMoney: " << "$" << m_moneyInAccount;
	std::cout << "\nAccount type: " << m_accountType;
	std::cout << "\nAccount Number: " << m_accountNumber;
}

void Account::setAccountType(Account &account) {
	account.m_accountType = "Current";
}

void Account::initialSetup() {
	setFirstName();
	setLastName();
}

void Account::setAccountNumber(int num) {
	m_accountNumber = num;
}

void Account::setLastName() {
	std::cout << "Last name: ";
	std::string name{};
	std::cin >> name;
	m_lastName = name;
}

std::string Account::printName()const {
	std::string fn{m_firstName};
	std::string ln{m_lastName};
	std::string nn{ fn + " " + ln };
	return nn;
}

int Account::getAccountNum()const {
	return m_accountNumber;
}

int Account::getAccountTotal(){
	return m_AccountTotals;
}

double Account::getMoneyInAccount()const {
	return m_moneyInAccount;
}

Account::~Account(){
	--m_AccountTotals;
}

