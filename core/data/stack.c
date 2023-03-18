#include "stack.h"
#include <stdlib.h>
#include <string.h>

void push(stack* current, char* value) {
  node* new_node = malloc(sizeof(node));
  if (new_node == NULL)
    exit(EXIT_FAILURE);
  new_node->value = malloc(strlen(value) + 1);
  strcpy(new_node->value, value);
  new_node->next = *current;
  *current = new_node;
}

char* pop(stack* current) {
  if (*current == NULL)
    exit(EXIT_FAILURE);
  char* response = malloc(strlen((*current)->value) + 1);
  strcpy(response, (*current)->value);
  *current = (*current)->next;
  return response;
}

bool empty(stack* current) {
  return (*current == NULL);
}