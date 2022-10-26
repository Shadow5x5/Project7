#pragma once
#include <fstream>
#include <iostream>
#include "Encryption.h"
#include <fstream>
class PIN_code
{
private:
    int PinCodeNumber;
    int KeyNumber;
    Encryption enc;
public:
    PIN_code(){
        PinCodeNumber = 1111;
        KeyNumber = 0000;
        //enc.addPinCode(PinCodeNumber, KeyNumber);
    }
    void addPinCode() {
        std::cout << "PIN: ";
        std::cin >> PinCodeNumber;
        std::cout << "Key number: ";
        std::cin >> KeyNumber;
        enc.addPinCode(PinCodeNumber, KeyNumber);
    }
    bool pincode_verification(int pincode, int key) {
        std::cout << enc.decrypt(key) << std::endl;
        std::cout << std::to_string(pincode) << std::endl;
        if (enc.decrypt(key) == std::to_string(pincode)) {
            return false;
        }
        else {
            return true;
        }
    }
    int getKeyNumber() {
        return KeyNumber;
    }

};

