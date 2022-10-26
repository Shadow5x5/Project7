#pragma once
#include "Transaction.h"
#include "Bank_card.h"
#include "PIN_code.h"
#include "Payment_for_the_phone.h"
#include "Payment_of_a_fine_from_the_traffic_police.h"
#include "Payment_TV.h"
#include <list>
class ATM_machine
{
private:
	struct Banknote
	{
		int nominal_value;
		int quantity;
	};
	std::list<Banknote> Banknotes;
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
	int money_at_the_ATM() {
		int sum = 0;
		for (Banknote a : Banknotes) {
			sum += (a.quantity * a.nominal_value);
		}
		return sum;
	}
	void cash_withdrawals(Bank_card& BC) {
		int sum;
		std::cout << "How much money do you want to cash out from the card?" << std::endl;
		std::cin >> sum;
		for (Banknote a : Banknotes) {
			std::cout << a.quantity << std::endl;
		}
		if (money_at_the_ATM() < sum) {
			std::cout << money_at_the_ATM() << std::endl;
			return;
		}
		else {
			int array[4];
			int sum2 = 0;
			int i = 0;
			for (Banknote& a : Banknotes) {
				if (a.quantity == 0) {
					break;
				}
				switch (i++)
				{
				case 3: array[0] = (sum - array[1] * 25 - (array[2] * 50) - (array[3] * 100)) / 1; break;
				case 2: array[1] = (sum - array[2] * 50 - (array[3] * 100)) / 25; break;
				case 1: array[2] = (sum - array[3] * 100) / 50; break;
				case 0: array[3] = sum / 100; break;
				default:
					break;
				}
			}
			i = 0;
			for (Banknote& a : Banknotes) {
				if (a.quantity < array[i]) {
					continue;
				}
				else {
					a.quantity -= array[i];
					sum2 += a.nominal_value * array[i];
				}
				i++;
			}
			if (sum == sum2) {
				std::cout << "The money has been successfully cashed out" << std::endl;
			}
			else {
				std::cout << "Insufficient funds at the ATM" << std::endl;
			}

		}
		system("pause");
	}
public:
	ATM_machine() {
		Banknote a;
		a.nominal_value = 1;
		a.quantity = rand() % 25 + 1;
		Sleep(1000);
		Banknotes.push_back(a);
		a.nominal_value = 25;
		a.quantity = rand() % 10 + 1;
		Sleep(1000);
		Banknotes.push_back(a);
		a.nominal_value = 50;
		a.quantity = rand() % 10 + 1;
		Sleep(1000);
		Banknotes.push_back(a);
		a.nominal_value = 100;
		a.quantity = rand() % 10 + 1;
		Sleep(1000);
		Banknotes.push_back(a);
	}
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

