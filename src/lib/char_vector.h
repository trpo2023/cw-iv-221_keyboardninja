#pragma once

#include <stddef.h>

typedef struct CharVector {
    char* data;
    size_t size;
    size_t capacity;
} CharVector;

CharVector* char_vector_new(size_t capacity);

void char_vector_free(CharVector* v);

int char_vector_push_back(CharVector* v, char item);
