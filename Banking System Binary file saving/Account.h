#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>

class Account {
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_accountType;
	long m_accountNumber;
	static int m_AccountTotals;
public:
	double m_moneyInAccount;
	Account();
	bool withdraw();
	void deposit();
	void setFirstName();
	void setLastName();
	void setAccountType(Account &account);
	void setAccountNumber(int num);
	void initialSetup();
	void print()const;
	int getAccountNum()const;
	double getMoneyInAccount()const;
	std::string printName()const;
	static int getAccountTotal();
	void getAccountType(Account &account);
	~Account();
};

#endif