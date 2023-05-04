#pragma once

#include <lib/char_vector.h>

#define MAX_STRING_SIZE 400
#define NOT_NUMBER -1
#define EARLY_TERMINATION_OF_THE_PROGRAM 8
#define CORRECT_WORKING_OUT 0

int stok(char* src, char symb, char** strs);

void unstok(char* str, char delim, char** ptr, int cnt);

int get_type_of_text(char type);

FILE* opening_file(FILE* string, int type, int random_num_of_future_text);

void input(CharVector* vector, FILE* string);

void output(CharVector* vector, CharVector* cpy_vector, int faults);

int process(CharVector* vector, CharVector* cpy_vector, int* faults);