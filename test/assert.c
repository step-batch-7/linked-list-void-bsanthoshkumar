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

void it(char *message, Callback callback)
{
  if (callback())
  {
    printf("✔ %s", message);
  }
  else
  {
    printf("✗ %s", message);
  }
}