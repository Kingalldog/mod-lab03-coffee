#include "Automata.h"

int main() {
    Automata* automata = new Automata();
    automata->on();
    automata->getMenu();
    automata->coin(30);
    std::cout << automata->choice("capuchino") << "\n";
    std::cout << automata->choice("cacao") << "\n";
    automata->coin(0);
    std::cout << automata->choice("cacao") << "\n";
    return 0;
}