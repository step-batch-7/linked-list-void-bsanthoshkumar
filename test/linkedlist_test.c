#include "../linkedlist.h"
#include "assert.h"
#include <stdio.h>

Boolean test_add_to_list()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  flag = flag && assert_status_equal(add_to_list(list, a), Success);
  flag = flag && assert_numbers_equal(list->length, 1);
  flag = flag && assert_status_equal(*(int *)list->first->element, *a);
  free(list);
  free(a);

  return flag;
}

Boolean test_add_to_start()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  flag = flag && assert_status_equal(add_to_start(list, a), Success);
  flag = flag && assert_numbers_equal(list->length, 1);
  flag = flag && assert_status_equal(*(int *)list->first->element, *a);
  free(list);
  free(a);

  return flag;
}

Boolean test_insert_at()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  add_to_list(list, a);
  int *b = malloc(sizeof(int));
  *b = 10;
  add_to_list(list, b);
  int *c = malloc(sizeof(int));
  *c = 10;
  flag = flag && assert_status_equal(insert_at(list, a, 1), Success);
  flag = flag && assert_numbers_equal(list->length, 3);
  flag = flag && assert_status_equal(*(int *)list->first->next->element, *c);
  free(list);
  free(a);

  return flag;
}

Status is_even(Element element)
{
  return *(int *)element % 2 == 0;
}

Boolean test_filter()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 1;
  add_to_list(list, a);
  int *b = malloc(sizeof(int));
  *b = 2;
  add_to_list(list, b);
  int *c = malloc(sizeof(int));
  *c = 3;
  add_to_list(list, c);
  int *d = malloc(sizeof(int));
  *d = 4;
  add_to_list(list, d);
  List_ptr filtered_list = filter(list, &is_even);
  flag = flag && assert_numbers_equal(filtered_list->length, 2);
  flag = flag && assert_numbers_equal(*(int *)(filtered_list->first->element), 2);
  flag = flag && assert_numbers_equal(*(int *)(filtered_list->last->element), 4);

  return flag;
}

Element sum(Element a, Element b)
{
  *(int *)a = *(int *)a + *(int *)b;
  return a;
}

Boolean test_reduce()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 1;
  add_to_list(list, a);
  int *b = malloc(sizeof(int));
  *b = 2;
  add_to_list(list, b);
  int *c = malloc(sizeof(int));
  *c = 3;
  add_to_list(list, c);
  int *d = malloc(sizeof(int));
  *d = 4;
  add_to_list(list, d);
  Element *reduced_element = malloc(sizeof(int));
  *reduced_element = 0;
  reduced_element = reduce(list, reduced_element, &sum);
  flag = flag && assert_numbers_equal(*(int *)(reduced_element), 10);

  return flag;
}

Status is_number_equal(Element a, Element b)
{
  return (*(int *)a) == (*(int *)b);
}

Boolean test_remove_all_occurrences()
{
  Boolean flag = True;
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  add_to_list(list, a);
  int *b = malloc(sizeof(int));
  *b = 20;
  add_to_list(list, b);
  int *c = malloc(sizeof(int));
  *c = 10;
  add_to_list(list, c);
  int *d = malloc(sizeof(int));
  *d = 30;
  add_to_list(list, d);
  Element *element = malloc(sizeof(int));
  *(int *)element = 10;
  List_ptr removed_elements_list = remove_all_occurrences(list, element, &is_number_equal);
  flag = flag && assert_numbers_equal(removed_elements_list->length, 2);
  flag = flag && assert_numbers_equal(*(int *)(removed_elements_list->first->element), 10);
  flag = flag && assert_numbers_equal(*(int *)(removed_elements_list->last->element), 10);

  return flag;
}

void run_tests()
{
  printf("running tests ....\n\n");

  it("Should insert element at end", &test_add_to_list);
  it("Should insert element at start", &test_add_to_start);
  it("Should insert element at position", &test_insert_at);
  it("Should filter all even numbers in a list", &test_filter);
  it("Should sum all numbers in a list", &test_reduce);
  it("Should remove all occurence of a number in a list", &test_remove_all_occurrences);
}

int main()
{
  run_tests();
}