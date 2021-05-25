#ifndef BUSINESS_ACCOUNT_H
#define BUSINESS_ACCOUNT_H
#include "Account.h"
#include <vector>

class Business_Account : public Account{
private:
	int m_allowedUsers;
	std::vector<std::string> m_names;
public:
	Business_Account();
	std::string addUser(std::string& name);
	void printAllowedUsers(std::vector<std::string> &m_names);
	void setFirstName();
	void setLastName();
	void setUserAmount(int& m_allowedUsers, std::vector<std::string>& m_names);
	void initialSetup(std::vector<std::string> &m_names);
};
#endif
