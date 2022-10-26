#pragma once
#include "Transaction.h"
class Payment_of_a_fine_from_the_traffic_police : Transaction
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

