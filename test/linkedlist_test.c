#include "../linkedlist.h"
#include "utilities.h"
#include "assert.h"
#include <stdio.h>

Boolean should_add_at_end()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  flag = flag && assert_status_equal(add_to_list(list, &a), Success);
  flag = flag && assert_numbers_equal(list->length, 1);
  flag = flag && assert_status_equal(*(int *)get_element(list, 0), a);
  free(list);

  return flag;
}

void test_add_to_list()
{
  it("Should insert element at end", &should_add_at_end);
  printf("\n");
}

Boolean should_add_at_start()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  flag = flag && assert_status_equal(add_to_start(list, &a), Success);
  flag = flag && assert_numbers_equal(list->length, 1);
  flag = flag && assert_status_equal(*(int *)get_element(list, 0), a);
  free(list);

  return flag;
}

void test_add_to_start()
{
  it("Should insert element at start", &should_add_at_start);
  printf("\n");
}

Boolean should_insert_at_0th_position()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  flag = flag && assert_status_equal(insert_at(list, &c, 0), Success);
  flag = flag && assert_numbers_equal(list->length, 3);
  flag = flag && assert_status_equal(*(int *)get_element(list, 0), c);
  free(list);

  return flag;
}

Boolean should_insert_in_any_middle_position()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  flag = flag && assert_status_equal(insert_at(list, &c, 1), Success);
  flag = flag && assert_numbers_equal(list->length, 3);
  flag = flag && assert_status_equal(*(int *)get_element(list, 1), c);
  free(list);

  return flag;
}

Boolean should_insert_at_last_position()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  flag = flag && assert_status_equal(insert_at(list, &c, 2), Success);
  flag = flag && assert_numbers_equal(list->length, 3);
  flag = flag && assert_status_equal(*(int *)get_element(list, 2), c);
  free(list);

  return flag;
}

Boolean should_not_insert_at_invalid_position()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  flag = flag && assert_status_equal(insert_at(list, &c, 5), Failure);
  flag = flag && assert_numbers_equal(list->length, 2);
  free(list);

  return flag;
}

void test_insert_at()
{
  it("Should insert element at 0th position", &should_insert_at_0th_position);
  it("Should insert element at any middle position", &should_insert_in_any_middle_position);
  it("Should insert element at last position", &should_insert_at_last_position);
  it("Should not insert element at invalid position", &should_not_insert_at_invalid_position);
  printf("\n");
}

Boolean filter_even_numbers()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 1;
  add_to_list(list, &a);
  int b = 2;
  add_to_list(list, &b);
  int c = 3;
  add_to_list(list, &c);
  int d = 4;
  add_to_list(list, &d);
  List_ptr filtered_list = filter(list, &is_even);
  flag = flag && assert_numbers_equal(filtered_list->length, 2);
  flag = flag && assert_numbers_equal(*(int *)get_element(filtered_list, 0), 2);
  flag = flag && assert_numbers_equal(*(int *)get_element(filtered_list, 1), 4);

  return flag;
}

void test_filter()
{
  it("Should filter all even numbers in a list", &filter_even_numbers);
  printf("\n");
}

Boolean sum_of_all_numbers_in_list()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 1;
  add_to_list(list, &a);
  int b = 2;
  add_to_list(list, &b);
  int c = 3;
  add_to_list(list, &c);
  int d = 4;
  add_to_list(list, &d);
  Element *reduced_element = malloc(sizeof(int));
  *reduced_element = 0;
  reduced_element = reduce(list, reduced_element, &sum);
  flag = flag && assert_numbers_equal(*(int *)(reduced_element), 10);

  return flag;
}

void test_reduce()
{
  it("Should give sum of all numbers in a list", &sum_of_all_numbers_in_list);
  printf("\n");
}

Boolean remove_morethan_one_occurrence()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 10;
  add_to_list(list, &c);
  int d = 30;
  add_to_list(list, &d);
  Element *element = malloc(sizeof(int));
  *(int *)element = 10;
  List_ptr removed_elements_list = remove_all_occurrences(list, element, &is_number_equal);
  flag = flag && assert_numbers_equal(removed_elements_list->length, 2);
  flag = flag && assert_numbers_equal(*(int *)get_element(removed_elements_list, 0), 10);
  flag = flag && assert_numbers_equal(*(int *)get_element(removed_elements_list, 1), 10);

  return flag;
}

void test_remove_all_occurrences()
{
  it("Should remove all occurence of a number in a list", &remove_morethan_one_occurrence);
  printf("\n");
}
void run_tests()
{
  printf("running tests ....\n\n");

  describe("add_to_list", &test_add_to_list);
  describe("add_to_start", &test_add_to_start);
  describe("insert_at", &test_insert_at);
  describe("filter", &test_filter);
  describe("reduce", &test_reduce);
  describe("remove_all_occurrences", &test_remove_all_occurrences);
}

int main()
{
  run_tests();
}