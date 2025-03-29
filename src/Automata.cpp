#include"Automata.h"

Automata::Automata(std::vector<std::string> Menu, std::vector<int32_t> Prices) : menu(Menu), prices(prices) { state = STATES::OFF;};
Automata::Automata() {
    state = STATES::OFF;
    std::ifstream fin;
    fin.open("../include/menu.txt");
    std::string line;
    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            menu.push_back(line);
        }
    }
    fin.close();
    fin.open("../include/price.txt");
    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            prices.push_back(std::stoi(line));
        }
    }
    fin.close();
};

bool Automata::on(){
    if(state != STATES::OFF) {
        return false;
    }
    cash = 0;
    state = STATES::WAIT;
    return true;
}
bool Automata::off() {
    if(state != STATES::WAIT) {
        return false;
    }
    state = STATES::OFF;
    return true;
}
bool Automata::coin(int32_t money) {
    if(money < 0) return false;
    if(state != STATES::WAIT && state != STATES::ACCEPT) {
        return false;
    }
    cash += money;
    state = STATES::ACCEPT;
    return true;
}
bool Automata::choice(std::string coffe_name) {
    if(state != STATES::ACCEPT) {
        return false;
    }
    state = STATES::CHECK;
    if(check(coffe_name)) {
        return true;
    } else {
        state = STATES::ACCEPT;
        return false;
    }
}
bool Automata::check(std::string coffe_name) {
    if(state != STATES::CHECK) {
        return false;
    }
    state = STATES::CHECK;
    size_t ind = -1;
    for(size_t i = 0; i< menu.size(); ++i){
        if(menu[i] == coffe_name){
            ind = i;
            break;
        }
    }
    return (ind >= 0 && cash >= prices[ind] && cook(coffe_name));
}
bool Automata::cook(std::string coffe_name) {
    if(state != STATES::CHECK) {
        return false;
    }
    state = STATES::COOK;
    size_t ind = -1;
    for(size_t i = 0; i< menu.size(); ++i){
        if(menu[i] == coffe_name){
            ind = i;
            break;
        }
    }
    cash -= prices[ind];
    sleep(1);
    return finish();
}
bool Automata::finish() {
    if(state != STATES::COOK) {
        return false;
    }
    state = STATES::WAIT;
    return true;
}
bool Automata::cancel() {
    if(state != STATES::ACCEPT && state != STATES::CHECK) {
        return false;
    }
    state = STATES::WAIT;
    return true;
}
void Automata::getMenu() {
    if(state != STATES::OFF) {
        for(size_t i = 0; i< menu.size(); ++i){
            std::cout << menu[i] << " " << prices[i] << "\n";
        }
    }
}
STATES Automata::getState() {
    return state;
}