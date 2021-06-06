#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

class Savings_Account : public Account{
private:
    double m_interest{};
    std::string m_accountType;
public:
    Savings_Account();
    void addInterest(Savings_Account& account);
    void print(Savings_Account& account)const;
    void setAccountType(Account& account);
    void initialSetup();
};
#endif
