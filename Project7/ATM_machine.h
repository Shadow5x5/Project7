#pragma once
#include "Transaction.h"
#include "Bank_card.h"
#include "PIN_code.h"
class ATM_machine
{
private:
	Transaction TN;
	void topping_up_the_card_in_cash(Bank_card& BC) {
		double Money;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		BC.setBalance(BC.getBalance() + Money);
	}
	void balance_on_the_card(Bank_card& BC) {
		std::cout << BC.getBalance() << std::endl;
	}
	void cash_withdrawals(Bank_card& BC) {
		int number;
		std::cout << "1:  25" << std::endl;
		std::cout << "2:  50" << std::endl;
		std::cout << "3: 100" << std::endl;
		std::cin >> number;
		switch (number)
		{
		case 1: BC.setBalance(BC.getBalance() - 25); break;
		case 2: BC.setBalance(BC.getBalance() - 50); break;
		case 3: BC.setBalance(BC.getBalance() - 100); break;
		default:
			break;
		}
	}
public:
	
	void Inserting_a_bank_card(Bank_card& BC) {
		int number, pincode, attempts = 3;
		while (attempts and BC.getCardBlocking()) {
			std::cout << "Enter the pincode: ";
			std::cin >> pincode;
			if (BC.getPinCode().pincode_verification(pincode, BC.getPinCode().getKeyNumber())) {
				attempts--;
			}
			else {
				break;
			}
			if (attempts == 0) {
				BC.setCardBlocking(false);
				std::cout << "You entered the password incorrectly, your card is blocked, please contact the bank." << std::endl;
				return;
			}
		}
		while (1) {
			system("cls");
			std::cout << "1: The balance of funds on the bank card" << std::endl; //Проверка баланса
			std::cout << "2: Cash withdrawal from a bank card" << std::endl; //Снятие наличных
			std::cout << "3: Bank card replenishment" << std::endl; //Пополнение
			std::cout << "4: Payment for services and fines" << std::endl;
			std::cout << "0: Exit" << std::endl;
			std::cin >> number;
			switch (number)
			{
			case 1: balance_on_the_card(BC); break;
			case 2: cash_withdrawals(BC); break;
			case 3: topping_up_the_card_in_cash(BC); break;
			case 4: 
				switch (TN.withdrawal_of_all_transactions())
				{
				case 1: TN.payment_for_the_phone(BC); break;
				case 2: TN.payment_TV(BC); break;
				case 3: TN.payment_of_a_fine_from_the_traffic_police(BC); break;
				default:
					break;
				}
			case 0: return;
			default:
				break;
			}
		}
	}
	
};

