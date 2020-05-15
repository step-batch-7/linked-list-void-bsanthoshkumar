#include "../linkedlist.h"
#include "utilities.h"
#include "assert.h"
#include <stdio.h>

Status should_add_at_end_in_empty_list()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  status = status && assert_status_equal(add_to_list(list, &a), Success);
  status = status && assert_numbers_equal(list->length, 1);
  status = status && assert_status_equal(*(int *)get_element(list, 0), a);
  free(list);

  return status;
}

Status should_add_at_end_in_non_empty_list()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  status = status && assert_status_equal(add_to_list(list, &b), Success);
  status = status && assert_numbers_equal(list->length, 2);
  status = status && assert_status_equal(*(int *)get_element(list, 1), b);
  free(list);

  return status;
}

void test_add_to_list()
{
  it("Should insert element at end in empty list", &should_add_at_end_in_empty_list);
  it("Should insert element at end in non empty list", &should_add_at_end_in_non_empty_list);
  printf("\n");
}

Status should_add_at_start_in_empty_list()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  status = status && assert_status_equal(add_to_start(list, &a), Success);
  status = status && assert_numbers_equal(list->length, 1);
  status = status && assert_status_equal(*(int *)get_element(list, 0), a);
  free(list);

  return status;
}

Status should_add_at_start_in_non_empty_list()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  status = status && assert_status_equal(add_to_start(list, &b), Success);
  status = status && assert_numbers_equal(list->length, 2);
  status = status && assert_status_equal(*(int *)get_element(list, 0), b);
  free(list);

  return status;
}

void test_add_to_start()
{
  it("Should insert element at start in empty list", &should_add_at_start_in_empty_list);
  it("Should insert element at start in non empty list", &should_add_at_start_in_non_empty_list);
  printf("\n");
}

Status should_insert_at_0th_position()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  status = status && assert_status_equal(insert_at(list, &c, 0), Success);
  status = status && assert_numbers_equal(list->length, 3);
  status = status && assert_status_equal(*(int *)get_element(list, 0), c);
  free(list);

  return status;
}

Status should_insert_in_any_middle_position()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  status = status && assert_status_equal(insert_at(list, &c, 1), Success);
  status = status && assert_numbers_equal(list->length, 3);
  status = status && assert_status_equal(*(int *)get_element(list, 1), c);
  free(list);

  return status;
}

Status should_insert_at_last_position()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  status = status && assert_status_equal(insert_at(list, &c, 2), Success);
  status = status && assert_numbers_equal(list->length, 3);
  status = status && assert_status_equal(*(int *)get_element(list, 2), c);
  free(list);

  return status;
}

Status should_not_insert_at_invalid_position()
{
  Status status = Success;
  List_ptr list = create_list();
  int a = 10;
  add_to_list(list, &a);
  int b = 20;
  add_to_list(list, &b);
  int c = 30;
  status = status && assert_status_equal(insert_at(list, &c, 5), Failure);
  status = status && assert_numbers_equal(list->length, 2);
  free(list);

  return status;
}

void test_insert_at()
{
  it("Should insert element at 0th position", &should_insert_at_0th_position);
  it("Should insert element at any middle position", &should_insert_in_any_middle_position);
  it("Should insert element at last position", &should_insert_at_last_position);
  it("Should not insert element at invalid position", &should_not_insert_at_invalid_position);
  printf("\n");
}

Status filter_even_numbers_in_non_empty_list()
{
  Status status = Success;
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
  status = status && assert_numbers_equal(filtered_list->length, 2);
  status = status && assert_numbers_equal(*(int *)get_element(filtered_list, 0), 2);
  status = status && assert_numbers_equal(*(int *)get_element(filtered_list, 1), 4);

  return status;
}

Status filter_even_numbers_in_empty_list()
{
  Status status = Success;
  List_ptr list = create_list();
  List_ptr filtered_list = filter(list, &is_even);
  status = status && assert_numbers_equal(filtered_list->length, 0);
  status = status && assert_is_null(filtered_list->first);
  status = status && assert_is_null(filtered_list->last);

  return status;
}

void test_filter()
{
  it("Should filter all even numbers in a list", &filter_even_numbers_in_non_empty_list);
  it("Should give empty list for filter for given empty list", &filter_even_numbers_in_empty_list);
  printf("\n");
}

Status sum_of_all_numbers_in_list()
{
  Status status = Success;
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
  status = status && assert_numbers_equal(*(int *)(reduced_element), 10);

  return status;
}

void test_reduce()
{
  it("Should give sum of all numbers in a list", &sum_of_all_numbers_in_list);
  printf("\n");
}

Status remove_morethan_one_occurrence()
{
  Status status = Success;
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
  status = status && assert_numbers_equal(removed_elements_list->length, 2);
  status = status && assert_numbers_equal(*(int *)get_element(removed_elements_list, 0), 10);
  status = status && assert_numbers_equal(*(int *)get_element(removed_elements_list, 1), 10);

  return status;
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