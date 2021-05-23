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
	static int m_AccountTotals;
public:
	Account();
	bool withdraw();
	void deposit();
	void setFirstName();
	void setLastName();
	void setAccountType();
	void setAccountNumber(int num);
	void initialSetup();
	void print()const;
	int getAccountNum()const;
	static int getAccountTotal();
	~Account();
};

#endif