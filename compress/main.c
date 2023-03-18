#include <stdio.h>
#include "data/stack.h"
#include "io/getline.h"
#include "data/vector.h"

typedef char* str;

define_vector(str)

int main() {
  /* TEMPORARY CODE FOR TESTING */
  FILE* stream;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  c_vector(str)* vector = NULL;
  vector = new_c_vector(str, 0);
  vector_iterator(str) *iter = (vector_iterator(str) *) new_vector_iterator(str, vector);
  generic_iterator *giter = (generic_iterator *) iter;

  stream = fopen("input.txt", "r");
  if (stream == NULL)
    exit(EXIT_FAILURE);

  char delimeter[] = " ";

  while ((read = getline(&line, &len, stream)) != -1) {
    char* saveptr;
    printf("Retrived line of length %zu: \n", read);
    printf("%s", line);
    char* p = strtok_r(line, delimeter, &saveptr);
    while (p != NULL) {
      vector->add_top(vector, strdup(p));
      printf("%s\n", p);
      p = strtok_r(NULL, delimeter, &saveptr);
    }
  }

  for (; !giter->end(giter); giter->next(giter))
    printf("Value at next index: %s\n", iter->current(iter));

  free(line);
  fclose(stream);
  exit(EXIT_SUCCESS);
}
