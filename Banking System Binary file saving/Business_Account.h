#ifndef BUSINESS_ACCOUNT_H
#define BUSINESS_ACCOUNT_H
#include "Account.h"
#include <vector>

class Business_Account : public Account{
private:
	int m_allowedUsers;
	std::vector<std::string> m_names;
	std::string m_accountType;
public:
	Business_Account();
	std::string addUser(std::string& name);
	void printAllowedUsers(std::vector<std::string> &m_names)const;
	void setFirstName();
	void setLastName();
	void setUserAmount(int& m_allowedUsers, std::vector<std::string>& m_names);
	void initialSetup();
	void print(Business_Account& account)const;
	void setAccountType(Account& account);
	void getAccountType(Account& account);
};
#endif
