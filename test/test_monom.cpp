#include <gtest/gtest.h>
#include<gmock/gmock.h>
#include "Monom.hpp"

// Test case to verify if a Monom can be created
TEST(Monom, CanCreateMonom) {
    std::vector<int> degrees = { 0, 0, 0 };
    ASSERT_NO_THROW(Monom<int>(0, degrees));
}

// Test case to verify if monoms can be summed
TEST(Monom, CanSumMonoms) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    ASSERT_NO_THROW(monom1 + monom2);
}

// Test case to verify if summing monoms is correct
TEST(Monom, IsSumMonomsCorrect) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    Monom<int> result = monom1 + monom2;
    Monom<int> expected(5, degrees);
    EXPECT_TRUE(expected == result);
}

// Test case to verify if monoms can be subtracted
TEST(Monom, CanSubtractMonoms) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    ASSERT_NO_THROW(monom1 - monom2);
}

// Test case to verify if subtracting monoms is correct
TEST(Monom, IsSubtractMonomsCorrect) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    Monom<int> result = monom1 - monom2;
    Monom<int> expected(-5, degrees);
    EXPECT_TRUE(expected == result);
}

// Test case to verify if monoms can be multiplied
TEST(Monom, CanMultiplyMonoms) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    ASSERT_NO_THROW(monom1 * monom2);
}

// Test case to verify if multiplying monoms is correct
TEST(Monom, IsMultiplyMonomsCorrect) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom1(0, degrees);
    Monom<int> monom2(5, degrees);
    Monom<int> result = monom1 * monom2;
    Monom<int> expected(0, degrees);
    EXPECT_TRUE(expected == result);
}

// Test case to verify if multiplying a monom by a scalar is correct
TEST(Monom, IsMultiplyMonomAndScalarCorrect) {
    std::vector<int> degrees = { 0, 0, 0 };

    Monom<int> monom2(5, degrees);
    Monom<int> result = monom2 * 5;
    Monom<int> expected(25, degrees);
    EXPECT_TRUE(expected == result);
}
