#include "Savings_Account.h"

Savings_Account::Savings_Account() : m_interest{5} {
}

void Savings_Account::addInterest(Savings_Account& account){
	double amount;
	amount = ((account.m_moneyInAccount * account.m_interest) / 100);
	m_moneyInAccount += amount;
}

void Savings_Account::print(Savings_Account& account) const{
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "ACCOUNT DETAILS";
	std::cout << "\n-----------------------------------------------\n";
	std::cout << "Name: " << Account::printName();
	std::cout << "\nMoney: " << "$" << m_moneyInAccount;
	std::cout << "\nAccount type: " << m_accountType;
	std::cout << "\nAccount Number: " << account.getAccountNum();
}

void Savings_Account::setAccountType(Account& account){
	m_accountType = "Savings";
}

void Savings_Account::initialSetup() {
	Account::setFirstName();
	Account::setLastName();
}

