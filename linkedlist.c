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

Status insert_at(List_ptr list, Element element, int position)
{
  if (position < 0 || position > list->length)
  {
    return Failure;
  }
  if (position == 0)
  {
    return add_to_start(list, element);
  }

  int temp = 1;
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->first;

  while (temp <= position)
  {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    temp++;
  }

  Node_ptr newnode = create_newnode(element);
  pair->prev->next = newnode;
  newnode->next = pair->current;
  list->length++;

  return Success;
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr current = list->first;
  while (current != NULL)
  {
    if (matcher(current->element, element))
    {
      return Failure;
    }
    current = current->next;
  }

  return add_to_end(list, element);
}

Element remove_from_start(List_ptr list)
{
  if (list->first == NULL)
  {
    return Failure;
  }

  Node_ptr node = list->first;
  list->first = list->first->next;
  if (list->length == 1)
  {
    list->last = list->first;
  }
  list->length--;

  return node->element;
}

Element remove_from_end(List_ptr list)
{
  if (list->last == NULL)
  {
    return Failure;
  }

  if (list->length == 1)
  {
    return remove_from_start(list);
  }

  Node_ptr current = list->first;
  while (current->next != list->last)
  {
    current = current->next;
  }

  list->last = current;
  list->last->next = NULL;
  list->length--;

  current = current->next;
  return current->element;
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