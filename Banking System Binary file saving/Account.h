#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>

class Account {
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_accountType;
	double m_moneyInAccount;
	long m_accountNumber;
public:
	Account()
		: m_firstName{ "" }, m_lastName{ "" }, m_accountType{ "" }, m_moneyInAccount{ 0.00 }, m_accountNumber{ 0 } {}
	bool withdraw();
	void deposit();
	void setFirstName();
	void setLastName();
	void setAccountType();
	void setAccountNumber(int num);
	void initialSetup();
	void print();
	int getAccountNum();
	~Account();
};

#endif