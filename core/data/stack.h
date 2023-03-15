#include <stdbool.h>

typedef struct node {
  char* value;
  struct node* next;
} node;

typedef node* stack;

void push(stack* current, char* value);
char* pop(stack* current);
bool empty(stack* current);