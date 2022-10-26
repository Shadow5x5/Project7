#pragma once
#include "Transaction.h"
#include "Bank_card.h"
#include "PIN_code.h"
#include "Payment_for_the_phone.h"
#include "Payment_of_a_fine_from_the_traffic_police.h"
#include "Payment_TV.h"
class ATM_machine
{
private:
	Payment_for_the_phone Transaction1;
	Payment_of_a_fine_from_the_traffic_police Transaction2;
	Payment_TV Transaction3;
	void topping_up_the_card_in_cash(Bank_card& BC) {
		double Money;
		std::cout << "Amount of money: ";
		std::cin >> Money;
		BC.setBalance(BC.getBalance() + Money);
		system("pause");
	}
	void balance_on_the_card(Bank_card& BC) {
		std::cout << BC.getBalance() << std::endl;
		system("pause");
	}
	void cash_withdrawals(Bank_card& BC) {
		int number;
		std::cout << "1:  25" << std::endl;
		std::cout << "2:  50" << std::endl;
		std::cout << "3: 100" << std::endl;
		std::cin >> number;
		switch (number)
		{
		case 1: 
			if (BC.getBalance() < 25) {
				std::cout << "There are not enough funds in your account!!!" << std::endl;
			}
			else {
				BC.setBalance(BC.getBalance() - 25); 
			}break;
		case 2:
			if (BC.getBalance() < 50) {
				std::cout << "There are not enough funds in your account!!!" << std::endl;
			}
			else {
				BC.setBalance(BC.getBalance() - 50);
			}break;
		case 3: 
			if (BC.getBalance() < 100) {
				std::cout << "There are not enough funds in your account!!!" << std::endl;
			}
			else {
				BC.setBalance(BC.getBalance() - 100);
			}break;
		default:
			break;
		}
		system("pause");
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
				std::cout << "1: Payment for telephone communication" << std::endl;
				std::cout << "2: Payment for TV" << std::endl;
				std::cout << "3: Payment of traffic fines" << std::endl;
				std::cin >> number;
				switch (number)
				{
				case 1: Transaction1.Payment(BC); break;
				case 2: Transaction2.Payment(BC); break;
				case 3: Transaction3.Payment(BC); break;
				default:
					break;
				} break;
			case 0: return;
			default:
				break;
			}
		}
	}
	
};

