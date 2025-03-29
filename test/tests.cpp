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
    automata->choice("cacao");
    result = automata->getState();
    ASSERT_EQ(STATES::WAIT, result);
  }

 
  TEST(task2, test2) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(30);
    STATES result = automata->getState();
    ASSERT_EQ(STATES::ACCEPT, result);
    ASSERT_EQ(true, automata->choice("cacao"));
  }
  
  TEST(task2, test3) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(10);
    ASSERT_EQ(false, automata->choice("cacao"));
  }
  
  TEST(task2, test4) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(120);
    EXPECT_EQ(true, automata->choice("capuchino"));
  }
  
  TEST(task2, test5) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(-10);
    EXPECT_EQ(STATES::WAIT, automata->getState());
  }
  
  TEST(task2, test6) {
    Automata* automata = new Automata();
    automata->on();
    automata->coin(90);
    automata->coin(10);
    ASSERT_EQ(true, automata->choice("capuchino"));
  }