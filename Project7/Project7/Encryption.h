#pragma once
#include <string>
#include <fstream>
class Encryption
{
private:
    int Key;
    std::string File = "geeksforgeeks.txt";
    char c;
public:
    void addPinCode(int PinCodeNumber,int Key) {
        std::string PinCodeNumberString = std::to_string(PinCodeNumber);
        std::fstream fin, fout;
        fout.open(File, std::fstream::out);
        fout << PinCodeNumberString;
        this->Key = Key;
        fout.close();
        encrypt();
    }

    void encrypt() {
        std::fstream fin, fout;
        fin.open(File, std::fstream::in);
        fout.open("encrypt.txt", std::fstream::out);
        while (fin >> std::noskipws >> c) {
            int temp = (c + Key);
            fout << (char)temp;
        }
        fin.close();
        fout.close();
        Key = NAN;
    }

    std::string decrypt(int Key) {
        std::string str;
        std::fstream fin;
        std::fstream fout;
        fin.open("encrypt.txt", std::fstream::in);
        fout.open("decrypt.txt", std::fstream::out);
        while (fin >> std::noskipws >> c) {
            int temp = (c - Key);
            fout << (char)temp;
        }
        fin.close();
        fout.close();
        fin.open("decrypt.txt");
        std::getline(fin, str);
        fin.close();
        return str;
    }
};
