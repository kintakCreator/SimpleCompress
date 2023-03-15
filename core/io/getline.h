#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int64_t getline(char** line, size_t* len, FILE* fp);