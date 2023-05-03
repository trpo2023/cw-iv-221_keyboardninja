#pragma once

#include <lib/char_vector.h>

int stok(char *src, char symb, char **strs);

void unstok(char *str, char delim, char **ptr, int cnt);

void input(CharVector* vector, CharVector* cpy_vector, FILE* string);

void output(CharVector* vector, CharVector* cpy_vector, int faults);

int process(CharVector* vector, CharVector* cpy_vector, int* faults);