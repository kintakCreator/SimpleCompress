#include <stdio.h>
#include "data/stack.h"
#include "io/getline.h"

int main() {
  /* TEMPORARY CODE FOR TESTING */
  FILE* stream;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  stream = fopen("input.txt", "r");
  if (stream == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, stream)) != -1) {
    printf("Retrived line of length %zu: \n", read);
    printf("%s", line);
  }

  free(line);
  fclose(stream);
  exit(EXIT_SUCCESS);
}
