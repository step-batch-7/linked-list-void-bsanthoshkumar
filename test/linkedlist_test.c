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

  return flag;
}

void run_tests()
{
  printf("running tests ....\n\n");

  it("Should insert element at end", &test_add_to_list);
}

int main()
{
  run_tests();
}