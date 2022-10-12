#include <iostream>
#include "Bank_card.h"
#include "ATM_machine.h"

void funStart() {
	ATM_machine ATM1;
	Bank_card Card;
	Card.addBankCard();
	ATM1.Inserting_a_bank_card(Card);
}

int main() {
	funStart();
	return 0;
}