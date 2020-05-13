#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  int *a = malloc(sizeof(int));
  *a = 10;
  add_to_list(list, a);

  return 0;
}
