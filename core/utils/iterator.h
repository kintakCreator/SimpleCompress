#ifndef SIMPLECOMPRESS_ITERATOR_H
#define SIMPLECOMPRESS_ITERATOR_H

#ifndef __cplusplus
#include <stdbool.h>
#include <stdlib.h>
#endif

typedef struct generic_iterator {
  void (*first)(struct generic_iterator*);
  void (*next)(struct generic_iterator*);
  void (*last)(struct generic_iterator*);
  bool (*end)(struct generic_iterator*);
  struct generic_iterator* (*destroy_iterator)(struct generic_iterator*);
} generic_iterator;

generic_iterator* destroy_iterator(generic_iterator* iter) {
  if (iter == NULL)
    return NULL;
  free(iter);
  return NULL;
}

#endif //SIMPLECOMPRESS_ITERATOR_H
