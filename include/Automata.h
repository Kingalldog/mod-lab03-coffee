// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <unistd.h>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>

enum class STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
 private:
    int32_t cash;
    std::vector<std::string> menu;
    std::vector<int32_t> prices;
    STATES state;

    bool check(std::string coffe_name);
    bool cook(std::string coffe_name);
    bool finish();

 public:
    Automata();
    Automata(std::vector<std::string> Menu, std::vector<int32_t> Prices);
    bool off();
    bool on();
    bool coin(int32_t money);
    void getMenu();
    STATES getState();
    bool choice(std::string coffe_name);
    bool cancel();
};
#endif  // INCLUDE_AUTOMATA_H_
