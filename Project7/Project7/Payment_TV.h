#pragma once
#include "Transaction.h"
class Payment_TV : Transaction
{
private:

public:
	void Payment(Bank_card& BC) override {
		std::string PersonalAccountNumber;
		double Money;
		std::cout << "Personal account number: ";
		std::cin >> PersonalAccountNumber;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		if (Money > BC.getBalance()) {
			std::cout << "There are not enough funds in your account!!!" << std::endl;
		}
		BC.setBalance(BC.getBalance() - Money);
	}
};

