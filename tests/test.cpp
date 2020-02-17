// Copyright 2018 Your Name <your_email>

#include "header.hpp"
#include <gtest/gtest.h>

TEST(Example, EmptyTest)
{
  stack<int> test(6);
  int a = 1, b = 2, c = 3;

  test.push(a);
  test.push(b);
  test.push(c);
  test.push(4);
  test.push(5);
  test.push(6);

  EXPECT_EQ(test.head(), 6);
  EXPECT_EQ(test.pop(), 6);
  EXPECT_EQ(test.pop(), 5);
  EXPECT_EQ(test.pop(), 4);
  EXPECT_EQ(test.pop(), 3);
  EXPECT_EQ(test.pop(), 2);
  EXPECT_EQ(test.pop(), 1);
}

TEST(stack, Text)
{
  stack<int> test(6);
  test.push_emplace(1);
  test.push_emplace(2);
  test.push(3);
  test.push(4);
  test.push(5);
  test.push(6);

  EXPECT_EQ(std::is_move_assignable<stack<int>>, true);
  EXPECT_EQ(std::is_move_constructible<stack<int>>, true);

  EXPECT_EQ(test.head(), 6);
  EXPECT_EQ(test.pop(), 6);
  EXPECT_EQ(test.pop(), 5);
  EXPECT_EQ(test.pop(), 4);
  EXPECT_EQ(test.pop(), 3);
  EXPECT_EQ(test.pop(), 2);
  EXPECT_EQ(test.pop(), 1);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
