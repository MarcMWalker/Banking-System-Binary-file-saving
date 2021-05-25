#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

class Savings_Account : public Account{
private:
    double m_interest{};
public:
    Savings_Account();
    double addInterest(double interest, double deposited);
};
#endif
