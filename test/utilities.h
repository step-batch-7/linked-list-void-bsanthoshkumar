#include "../linkedlist.h"

#ifndef __UTILITIES_H
#define __UTILITIES_H

Element get_element(List_ptr, int);

Status is_even(Element element);
Status is_vowel(Element element);
Element sum(Element a, Element b);
Status is_number_equal(Element a, Element b);

#endif