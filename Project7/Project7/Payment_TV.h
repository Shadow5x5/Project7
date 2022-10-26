#pragma once
#include "Transaction.h"
class Payment_TV : Transaction
{
private:
	std::list<int> Personal_account_database;
public:
	Payment_TV() {
		for (int i = 0; i < 10; i++) {
			srand(time(NULL));
			Personal_account_database.push_back(rand() % 100 + 1);
			Sleep(1000);
		}
	}
	void Payment(Bank_card& BC) override {
		for (int a : Personal_account_database) {
			std::cout << a << " ";
		}
		std::cout << std::endl;
		std::string PersonalAccountNumber;
		for (int a : Personal_account_database) {
			if (std::to_string(a) == PersonalAccountNumber) {
				std::cout << "There is no such account!!!" << std::endl;
				return;
			}
			else {
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
		}
	}
};

