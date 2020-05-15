#include "../linkedlist.h"

Element get_element(List_ptr list, int position)
{
  if (position < 0 || position >= list->length)
  {
    return NULL;
  }
  int temp = 0;
  Node_ptr current = list->first;
  while (temp < position)
  {
    current = current->next;
    temp++;
  }

  return current->element;
}

Status is_even(Element element)
{
  return *(int *)element % 2 == 0;
}

Element sum(Element a, Element b)
{
  *(int *)a = *(int *)a + *(int *)b;
  return a;
}

Status is_number_equal(Element a, Element b)
{
  return (*(int *)a) == (*(int *)b);
}