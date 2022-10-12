#pragma once
#include <string>
#include "PIN_code.h"
class Bank_card
{
private:
	std::string Surname;
	std::string Name;
	std::string CardNumber;
	PIN_code PinCode;
	int CVV_CVC;
	double Balance;
	bool CardBlocking;
public:
	Bank_card() {
		Surname = "Ivanov";
		Name = "Ivan";
		CardNumber = "1234 5678 9123 4567";
		CVV_CVC = 000;
		CardBlocking = true;
	}
	void addBankCard() {
		std::cout << "Surname: ";
		std::cin >> Surname;
		std::cout << "Name: ";
		std::cin >> Name;
		std::cout << "Card number: ";
		std::cin >> CardNumber;
		std::cout << "CVV_CVC: ";
		std::cin >> CVV_CVC;
		PinCode.addPinCode();
		std::cout << "Balance: ";
		std::cin >> Balance;
		CardBlocking = true;
		system("cls");

	}
	double getBalance() {
		return Balance;
	}
	void setBalance(double b) {
		Balance = b;
	}
	PIN_code getPinCode() {
		return PinCode;
	}
	bool getCardBlocking() {
		return CardBlocking;
	}
	void setCardBlocking(bool Flag) {
		CardBlocking = Flag;
	}
};

