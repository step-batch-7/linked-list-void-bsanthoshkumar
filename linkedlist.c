#include "linkedlist.h"
#include <stdlib.h>

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

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr newnode = create_newnode(element);
  if (list->first == NULL)
  {
    list->first = newnode;
  }
  else
  {
    list->last->next = newnode;
  }
  list->last = newnode;
  list->length++;

  return Success;
}

Status add_to_start(List_ptr list, Element element)
{
  Node_ptr newnode = create_newnode(element);
  newnode->next = list->first;
  list->first = newnode;
  if (list->last == NULL)
  {
    list->last = newnode;
  }
  list->length++;

  return Success;
}

void display_number(Element element)
{
  printf("%d ", *(int *)element);
}

void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr current = list->first;
  while (current != NULL)
  {
    processor(current->element);
    current = current->next;
  }
}