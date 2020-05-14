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

Prev_Current_Pair_ptr move_to(List_ptr list, int position)
{
  int temp = 1;
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->first;

  while (temp <= position)
  {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    temp++;
  }

  return pair;
}

Status add_to_list(List_ptr list, Element element)
{
  Node_ptr newnode = create_newnode(element);
  if (newnode == NULL)
  {
    return Failure;
  }
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
  if (newnode == NULL)
  {
    return Failure;
  }
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

  Prev_Current_Pair_ptr pair = move_to(list, position);
  Node_ptr newnode = create_newnode(element);
  if (newnode == NULL)
  {
    return Failure;
  }

  pair->prev->next = newnode;
  newnode->next = pair->current;
  if (newnode->next == NULL)
  {
    list->last = newnode;
  }
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

  return add_to_list(list, element);
}

Element remove_from_start(List_ptr list)
{
  if (list->first == NULL)
  {
    return NULL;
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
    return NULL;
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
  current = current->next;
  list->last->next = NULL;
  list->length--;

  return current->element;
}

Element remove_at(List_ptr list, int position)
{
  if (position < 0 || position >= list->length)
  {
    return NULL;
  }

  if (position == 0)
  {
    return remove_from_start(list);
  }

  Prev_Current_Pair_ptr pair = move_to(list, position);
  pair->prev->next = pair->current->next;
  if (pair->prev->next == NULL)
  {
    list->last = pair->prev;
  }
  list->length--;

  return pair->current->element;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
  int position = 0;
  Node_ptr current = list->first;
  while (current != NULL)
  {
    if (matcher(current->element, element))
    {
      return remove_at(list, position);
    }
    current = current->next;
    position++;
  }

  return NULL;
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher)
{
  List_ptr removed_elements_list = create_list();
  Element removed_element;

  while (removed_element != NULL)
  {
    removed_element = remove_first_occurrence(list, element, matcher);
    add_to_list(removed_elements_list, removed_element);
  }

  return removed_elements_list;
}

Status clear_list(List_ptr list)
{
  if (list->first == NULL)
  {
    return Failure;
  }

  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->first;
  while (pair->current != NULL)
  {
    pair->prev = pair->current;
    pair->current = pair->current->next;
    free(pair->prev);
  }

  list->first = NULL;
  list->last = NULL;
  list->length = 0;

  return Success;
}

List_ptr reverse(List_ptr list)
{
  Prev_Current_Pair_ptr pair = malloc(sizeof(Prev_Current_Pair));
  pair->current = list->first;
  pair->prev = NULL;
  while (pair->current != NULL)
  {
    Node_ptr temp_node = pair->current;
    pair->current = pair->current->next;
    temp_node->next = pair->prev;
    pair->prev = temp_node;
  }

  pair->current = list->first;
  list->first = list->last;
  list->last = pair->current;

  return list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr mapped_array = create_list();
  Node_ptr current = list->first;
  while (current != NULL)
  {
    Element mapped_element = (*mapper)(current->element);
    add_to_list(mapped_array, mapped_element);
  }

  return mapped_array;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  List_ptr filtered_list = create_list();
  Node_ptr current = list->first;
  while (current != NULL)
  {
    if ((*predicate)(current->element))
    {
      add_to_list(filtered_list, current->element);
    }
  }

  return filtered_list;
}

Element reduce(List_ptr list, Element element, Reducer reducer)
{
  Element reduced_value = element;
  Node_ptr current = list->first;
  while (current != NULL)
  {
    reduced_value = (*reducer)(reduced_value, current->element);
    current = current->next;
  }

  return reduced_value;
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