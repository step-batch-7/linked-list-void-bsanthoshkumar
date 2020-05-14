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

void run_tests()
{
  printf("running tests ....\n\n");

  it("Should insert element at end", &test_add_to_list);
  it("Should insert element at start", &test_add_to_start);
  it("Should insert element at position", &test_insert_at);
}

int main()
{
  run_tests();
}