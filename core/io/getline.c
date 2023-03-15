#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include "getline.h"

int64_t getline(char ** line, size_t * len, FILE * fp) {
  if (line == NULL || len == NULL || fp == NULL) {
    errno = EINVAL;
    return -1;
  }
  char chunk[128];
  if (*line == NULL || *len < sizeof(chunk)) {
    *len = sizeof(chunk);
    if ((*line = malloc(*len)) == NULL) {
      errno = ENOMEM;
      return -1;
    }
  }
  (*line)[0] = '\0';
  while (fgets(chunk, sizeof(chunk), fp) != NULL) {
    size_t len_used = strlen(*line);
    size_t chunk_used = strlen(chunk);
    if (*len - len_used < chunk_used) {
      if (*len > SIZE_MAX / 2) {
        errno = EOVERFLOW;
        return -1;
      } else {
        *len *= 2;
      }
      if ((*line = realloc(*line, *len)) == NULL) {
        errno = ENOMEM;
        return -1;
      }
    }
    memcpy(*line + len_used, chunk, chunk_used);
    len_used += chunk_used;
    (*line)[len_used] = '\0';
    if ((*line)[len_used - 1] == '\n') {
      return len_used; // here's a warning, I think it should be fixed
    }
  }
  return -1;
}