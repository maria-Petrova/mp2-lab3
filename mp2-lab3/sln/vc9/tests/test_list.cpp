#include <gtest.h>

#include "list.h"
#include "list.cpp"

TEST(List, can_create_list) {
  list<char> *List;
  ASSERT_NO_THROW(List = new list<char>);
}

TEST(List, can_create_copied_list) {
  list<char> list1;
  list1.insertL(1);
  ASSERT_NO_THROW(list<char> list2(list1));
}

TEST(List, copied_list_is_equal_to_sourse_one) {
  list<char> list1;
  list1.insertL(2);
  list<char> list2(list1);
  EXPECT_EQ(list2.GetFirst()->val, 2);
}

TEST(List, copied_list_has_its_own_memory) {
  list<char> list1;
  list1.insertL(1);
  list<char> list2(list1);
  list2.insertL(2);
  list2.del(1);
  EXPECT_NE(list2.GetFirst()->val, list1.GetFirst()->val);
}

TEST(List, can_print_empty_list) {
  list<char> list1;
  ASSERT_NO_THROW(list1.print());
}

TEST(List, can_search_element_with_actual_value) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  list1.insertL(-2);
  list1.insertL(8);
  ASSERT_TRUE(list1.poisk(-2) != 0);
}

TEST(List, return_null_when_cant_search_element) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  list1.insertL(-2);
  list1.insertL(8);
  ASSERT_TRUE(list1.poisk(0) == 0);
}

TEST(List, throws_when_search_in_empty_list) {
  list<char> list1;
  ASSERT_ANY_THROW(list1.poisk(9));
}

TEST(List, can_delete_element_with_actual_value) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  list1.insertL(-2);
  list1.insertL(8);
  ASSERT_NO_THROW(list1.del(-2));
}

TEST(List, return_null_when_delete_not_actual_value) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  EXPECT_EQ(0,list1.del(1));
}

TEST(List, can_delete_first_element) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  ASSERT_NO_THROW(list1.del(12));
}

TEST(List, can_not_find_delete_element) {
  list<char> list1;
  list1.insertL(12);
  list1.insertL(6);
  list1.del(6);
  ASSERT_FALSE(list1.poisk(6));
}

TEST(List, throws_when_try_delete_in_empty_list) {
  list<char> list;
  ASSERT_ANY_THROW(list.del(1));
}

TEST(List, can_insert_first_element) {
  list<char> list;
  ASSERT_NO_THROW(list.insertF(12));
  EXPECT_EQ(12, list.GetFirst()->val);
}

TEST(List, can_insert_last_element) {
  list<char> list;
  list.insertF(12);
  ASSERT_NO_THROW(list.insertL(15));
}

TEST(List, can_insert_last_element_when_list_is_empty) {
  list<char> list;
  ASSERT_NO_THROW(list.insertL(12));
  EXPECT_EQ(12, list.GetFirst()->val);
}

TEST(List, can_insert_after) {
  list<char> list;
  list.insertL(12);
  list.insertL(6);
  list.insertL(-2);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_NO_THROW(list.insertA(6, a));
}

TEST(List, can_insert_after_when_it_last) {
  list<char> list;
  list.insertL(12);
  list.insertL(6);
  list.insertL(-2);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_NO_THROW(list.insertA(-2, a));
}

TEST(List, throws_when_cant_find_place_to_insert_after) {
  list<char> list;
  list.insertL(12);
  list.insertL(6);
  list.insertL(-2);
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_ANY_THROW(list.insertA(14, a));
}

TEST(List, throws_when_insert_after_in_empty_list) {
  list<char> list;
  node<char>* a = new node<char>;
  a->val = 1;
  ASSERT_ANY_THROW(list.insertA(5, a));
}

TEST(List, can_get_first) {
  list<char> list;
  list.insertL(12);
  list.insertL(6);
  list.insertL(-2);
  ASSERT_NO_THROW(list.GetFirst());
  EXPECT_EQ(12, list.GetFirst()->val);
}
