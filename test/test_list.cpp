#include <gtest/gtest.h>
#include<gmock/gmock.h>
#include "SingleLinkedList.hpp"

// Test case to verify if a list can be created
TEST(SingleLinkedList, CanCreateList) {
    SingleLinkedList<int> list;
    EXPECT_EQ(0, list.GetSize());
}

// Test case to verify if an element can be added to the list
TEST(SingleLinkedList, CanAddElement) {
    SingleLinkedList<int> list;
    list.push_back(5);
    EXPECT_EQ(1, list.GetSize());
    EXPECT_EQ(5, list[0]);
}

// Test case to verify if an element can be removed from the list
TEST(SingleLinkedList, CanRemoveElement) {
    SingleLinkedList<int> list;
    list.push_back(5);
    list.pop_back();
    EXPECT_EQ(0, list.GetSize());
}

// Test case to verify if the list is cleared correctly
TEST(SingleLinkedList, CanClearList) {
    SingleLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.clear();
    EXPECT_EQ(0, list.GetSize());
}

// Test case to verify if elements can be accessed by index
TEST(SingleLinkedList, CanAccessElementsByIndex) {
    SingleLinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    EXPECT_EQ(5, list[0]);
    EXPECT_EQ(10, list[1]);
}
//
//// Test case to verify if two lists with the same elements are equal
//TEST(SingleLinkedList, EqualListsAreEqual) {
//    SingleLinkedList<int> list1;
//    list1.push_back(5);
//    list1.push_back(10);
//
//    SingleLinkedList<int> list2;
//    list2.push_back(5);
//    list2.push_back(10);
//
//    EXPECT_EQ(list1, list2);
//}
//
//// Test case to verify if two lists with different elements are not equal
//TEST(SingleLinkedList, DifferentListsAreNotEqual) {
//    SingleLinkedList<int> list1;
//    list1.push_back(5);
//    list1.push_back(10);
//
//    SingleLinkedList<int> list2;
//    list2.push_back(10);
//    list2.push_back(5);
//
//    EXPECT_NE(list1, list2);
//}
