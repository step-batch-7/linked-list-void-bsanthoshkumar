#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

Node_ptr create_newnode(Element element)
{
  Node_ptr newnode = malloc(sizeof(Node));
  newnode->element = element;
  newnode->next = NULL;
  return newnode;
}
