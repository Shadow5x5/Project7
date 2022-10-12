#pragma once
#include "Bank_card.h"
class Transaction
{
private:

public:
	int withdrawal_of_all_transactions() {
		int number;
		system("cls");
		std::cout << "1: Payment for telephone communication" << std::endl;
		std::cout << "2: Payment for TV" << std::endl;
		std::cout << "3: Payment of traffic fines" << std::endl;
		std::cin >> number;
		return number;

	}
	void payment_for_the_phone(Bank_card& BC) {
		std::string PhoneNumber;
		double Money;
		std::cout << "Phone number: ";
		std::cin >> PhoneNumber;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		BC.setBalance(BC.getBalance() - Money);
	}
	void payment_TV(Bank_card& BC) {
		std::string PersonalAccountNumber;
		double Money;
		std::cout << "Personal account number: ";
		std::cin >> PersonalAccountNumber;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		BC.setBalance(BC.getBalance() - Money);
	}
	void payment_of_a_fine_from_the_traffic_police(Bank_card& BC) {
		std::string PersonalAccountNumber;
		double Money;
		std::cout << "Personal account number: ";
		std::cin >> PersonalAccountNumber;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		BC.setBalance(BC.getBalance() - Money);
	}
};

