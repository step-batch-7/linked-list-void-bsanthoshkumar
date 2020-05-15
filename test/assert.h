#ifndef __ASSERT_H_
#define __ASSERT_H_

typedef enum
{
  False,
  True
} Boolean;

typedef int Integer;
typedef char Character;

typedef Status (*Callback)(void);
typedef void (*Function)(void);

void describe(char *functionname, Function function);
void it(char *message, Callback callback);
Boolean assert_status_equal(Status actual, Status expected);
Boolean assert_numbers_equal(Integer actual, Integer expected);
Boolean assert_characters_equal(Character actual, Character expected);

#endif