#include "../linkedlist.h"
#include "assert.h"
#include <stdio.h>

Boolean assert_status_equal(Status actual, Status expected)
{
  return actual == expected;
}

Boolean assert_numbers_equal(Integer actual, Integer expected)
{
  return actual == expected;
}

Boolean assert_characters_equal(Character actual, Character expected)
{
  return actual == expected;
}

Boolean assert_is_null(Element actual)
{
  return actual == NULL;
}

void describe(char *functionname, Function function)
{
  printf("   %s\n", functionname);
  function();
}

void it(char *message, Callback callback)
{
  if (callback())
  {
    printf("\t✔ %s\n", message);
  }
  else
  {
    printf("\t✗ %s\n", message);
  }
}