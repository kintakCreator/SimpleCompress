#ifndef SIMPLECOMPRESS_ERROR_H
#define SIMPLECOMPRESS_ERROR_H

#ifndef __cplusplus
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#else
#include <cstdio>
#include <cstdlib>
#include <cstring>
#endif

#define TO_STRING(ENUM) #ENUM

typedef struct error_info {
  char* filename;
  char* funcname;
  char* line;
  char* code;
} error_info;

error_info err_struct;

typedef enum error_code {
  success,
  realloc_failed,
  memset_failed,
  invalid_index,
  make_sentinels_failed,
  new_node_failed,
  basic_insert_failed,
  memcpy_failed,
  key_no_found,
  null_tree
} error_code;

static const char *error_code_string[] = {
  TO_STRING(success),
  TO_STRING(realloc_failed),
  TO_STRING(memset_failed),
  TO_STRING(invalid_index),
  TO_STRING(make_sentinels_failed),
  TO_STRING(new_node_failed),
  TO_STRING(basic_insert_failed),
  TO_STRING(memcpy_failed),
  TO_STRING(key_not_found),
  TO_STRING(null_tree)
};

error_code err;

#ifndef __GNUC__
  static inline void free_error_info() {
    if (err_struct.filename != NULL) {
      free(err_struct.filename);
      err_struct.filename = NULL;
    }
    if (err_struct.funcname != NULL) {
      free(err_struct.funcname);
      err_struct.funcname = NULL;
    }
    if (err_struct.line != NULL) {
      free(err_struct.line);
      err_struct.line = NULL;
    }
    if (err_struct.code != NULL) {
      free(err_struct.code);
      err_struct.code = NULL;
    }
  }
#else
  __attribute__((destructor)) static inline void free_error_info() {
    if (err_struct.filename != NULL) {
      free(err_struct.filename);
      err_struct.filename = NULL;
    }
    if (err_struct.funcname != NULL) {
      free(err_struct.funcname);
      err_struct.funcname = NULL;
    }
    if (err_struct.line != NULL) {
      free(err_struct.line);
      err_struct.line = NULL;
    }
    if (err_struct.code != NULL) {
      free(err_struct.code);
      err_struct.code = NULL;
    }
  }
#endif

static inline void set_error_info(char* filename, char* funcname, int line) {
  free_error_info();
  size_t arrsize = snprintf(NULL, 0, "%d", line);
  char* ptr = (char*) malloc(arrsize + 1);
  snprintf(ptr, arrsize + 1, "%d", line);
  err_struct.filename = strdup(filename);
  err_struct.funcname = strdup(funcname);
  err_struct.line = ptr;
  err_struct.code = strdup(error_code_string[err]);
}

#endif //SIMPLECOMPRESS_ERROR_H
