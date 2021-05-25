#include "Savings_Account.h"

Savings_Account::Savings_Account() : m_interest{5} {
}

double addInterest(double interest, double deposited) {
	double amount{};
	amount = deposited * interest / 100;
	return amount;
};
