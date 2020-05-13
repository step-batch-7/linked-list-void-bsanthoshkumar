#include "linkedlist.h"
#include <stdio.h>

int main()
{
  List_ptr list = create_list();

  int *a = malloc(sizeof(int));
  *a = 10;
  add_to_list(list, a);

  int *b = malloc(sizeof(int));
  *b = 20;
  add_to_start(list, b);

  int *c = malloc(sizeof(int));
  *c = 30;
  add_to_start(list, c);

  forEach(list, &display_number);
  reverse(list);
  printf("\n");
  forEach(list, &display_number);

  return 0;
}
