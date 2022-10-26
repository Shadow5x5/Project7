#pragma once
#include "Bank_card.h"
#include <list>
class Transaction
{
private:
	int Transaction_number;
	std::list<int> Number_of_all_transactions;
public:


	int withdrawal_of_all_transactions() {
		int number;
		system("cls");
		
		return number;

	}

	virtual void Payment(Bank_card& BC){
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

