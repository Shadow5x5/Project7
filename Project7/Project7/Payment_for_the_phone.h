#pragma once
#include "Transaction.h"
class Payment_for_the_phone : Transaction
{
private:

public:
	void Payment(Bank_card& BC) override {
		std::string PhoneNumber;
		double Money;
		std::cout << "Phone number: ";
		std::cin >> PhoneNumber;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		if (Money > BC.getBalance()) {
			std::cout << "There are not enough funds in your account!!!" << std::endl;
		}
		BC.setBalance(BC.getBalance() - Money);
	}
};

