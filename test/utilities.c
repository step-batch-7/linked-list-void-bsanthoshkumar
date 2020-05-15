#include "../linkedlist.h"

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