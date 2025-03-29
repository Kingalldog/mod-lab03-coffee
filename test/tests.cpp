// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


TEST(task1, test1) {
    Automata* automata = new Automata();
    ASSERT_EQ(STATES::OFF, automata->getState());
}
TEST(task1, test2) {
    std::stringstream strs;
    Automata* automata = new Automata();
    automata->on();
    ASSERT_EQ(STATES::WAIT, automata->getState());
}
TEST(task1, test3) {
    Automata* automata = new Automata();
    automata->on();
    automata->off();
    ASSERT_EQ(STATES::OFF, automata->getState());
}
TEST(task1, test4) {
    Automata* automata = new Automata();
    automata->on();
    automata->on();
    ASSERT_EQ(STATES::WAIT, automata->getState());
}
TEST(task2, test1) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(30);
    STATES result = automata->getState();
    ASSERT_EQ(STATES::ACCEPT, result);
}
TEST(task2, test2) {
    Automata* automata = new Automata();
    ASSERT_EQ(STATES::OFF, automata->getState());
}
TEST(task2, test3) {
    std::stringstream strs;
    Automata* automata = new Automata();
    automata->on();
    ASSERT_EQ(STATES::WAIT, automata->getState());
}
TEST(task2, test4) {
    Automata* automata = new Automata();
    automata->on();
    automata->off();
    ASSERT_EQ(STATES::OFF, automata->getState());
}
TEST(task2, test5) {
    Automata* automata = new Automata();
    automata->on();
    automata->on();
    ASSERT_EQ(STATES::WAIT, automata->getState());
}
TEST(task2, test6) {
    Automata* automata = new Automata();
    automata->on();
    automata->off();
    automata->on();
    ASSERT_EQ(STATES::WAIT, automata->getState());
}