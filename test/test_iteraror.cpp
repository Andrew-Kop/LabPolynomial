#include <gtest/gtest.h>
#include<gmock/gmock.h>
#include "Iterator.hpp"

// Test case to verify if an iterator can be created
TEST(Iterator, CanCreateIterator) {
    Node<int> node(5);
    Iterator<int> iter(&node);
    EXPECT_EQ(&node, iter.Getindex());
}

// Test case to verify if two iterators pointing to the same node are equal
TEST(Iterator, EqualIteratorsAreEqual) {
    Node<int> node(5);
    Iterator<int> iter1(&node);
    Iterator<int> iter2(&node);
    EXPECT_EQ(iter1, iter2);
}

// Test case to verify if two iterators pointing to different nodes are not equal
TEST(Iterator, DifferentIteratorsAreNotEqual) {
    Node<int> node1(5);
    Node<int> node2(10);
    Iterator<int> iter1(&node1);
    Iterator<int> iter2(&node2);
    EXPECT_NE(iter1, iter2);
}

// Test case to verify if dereferencing an iterator returns the correct value
TEST(Iterator, DereferenceOperatorReturnsCorrectValue) {
    Node<int> node(5);
    Iterator<int> iter(&node);
    EXPECT_EQ(5, *iter);
}

// Test case to verify if prefix increment operator works correctly
TEST(Iterator, PrefixIncrementOperatorWorks) {
    Node<int> node1(5);
    Node<int> node2(10);
    node1.Setptr(&node2);
    Iterator<int> iter(&node1);
    ++iter;
    EXPECT_EQ(&node2, iter.Getindex());
}

// Test case to verify if postfix increment operator works correctly
TEST(Iterator, PostfixIncrementOperatorWorks) {
    Node<int> node1(5);
    Node<int> node2(10);
    node1.Setptr(&node2);
    Iterator<int> iter(&node1);
    iter++;
    EXPECT_EQ(&node2, iter.Getindex());
}

// Test case to verify if addition operator works correctly
TEST(Iterator, AdditionOperatorWorks) {
    Node<int> node1(5);
    Node<int> node2(10);
    node1.Setptr(&node2);
    Iterator<int> iter(&node1);
    Iterator<int> result = iter + 1;
    EXPECT_EQ(&node2, result.Getindex());
}

// Test case to verify the assignment operator
TEST(Iterator, AssignmentOperatorWorks) {
    Node<int> node1(5);
    Node<int> node2(10);
    Iterator<int> iter1(&node1);
    Iterator<int> iter2(&node2);
    iter1 = iter2;
    EXPECT_EQ(iter1.Getindex(), iter2.Getindex());
}

// Test case to verify the prefix increment operator on a null iterator
TEST(Iterator, PrefixIncrementOnNullIteratorThrowsException) {
    Iterator<int> iter(nullptr);
    EXPECT_THROW(++iter, std::out_of_range);
}

// Test case to verify the postfix increment operator on a null iterator
TEST(Iterator, PostfixIncrementOnNullIteratorThrowsException) {
    Iterator<int> iter(nullptr);
    EXPECT_THROW(iter++, std::out_of_range);
}

// Test case to verify the dereference operator on a null iterator
TEST(Iterator, DereferenceOnNullIteratorThrowsException) {
    Iterator<int> iter(nullptr);
    EXPECT_THROW(*iter, std::out_of_range);
}

// Test case to verify the addition operator on a null iterator
TEST(Iterator, AdditionOperatorOnNullIteratorThrowsException) {
    Iterator<int> iter(nullptr);
    EXPECT_THROW(iter + 1, std::out_of_range);
}

// Test case to verify the addition operator with a valid iterator
TEST(Iterator, AdditionOperatorWithValidIteratorWorks) {
    Node<int> node1(5);
    Node<int> node2(10);
    node1.Setptr(&node2);
    Iterator<int> iter(&node1);
    Iterator<int> result = iter + 1;
    EXPECT_EQ(&node2, result.Getindex());
}
