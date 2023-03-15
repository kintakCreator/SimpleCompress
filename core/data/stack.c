#include "stack.h"
#include <stdlib.h>
#include <string.h>

void push(stack* current, char* value) {
  node* newNode = malloc(sizeof(node));
  if (newNode == NULL)
    exit(EXIT_FAILURE);
  newNode->value = malloc(strlen(value) + 1);
  strcpy(newNode->value, value);
  newNode->next = *current;
  *current = newNode;
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