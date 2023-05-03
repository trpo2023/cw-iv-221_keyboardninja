#include <stddef.h>
#include <stdlib.h>

#include <lib/char_vector.h>

CharVector* char_vector_new(size_t capacity) {
    CharVector* darr = (CharVector*)malloc(sizeof(CharVector));
    if (darr == NULL) {
        return NULL;
    }
    darr->size = 0;
    darr->capacity = capacity;
    darr->data = (char*)calloc(capacity, sizeof(char));
    if (darr->data == NULL) {
        free(darr);
        return NULL;
    }
    return darr;
    
}

void char_vector_free(CharVector* v) {
    free(v->data);
    v->data = NULL;
    free(v);
    v = NULL;

}

int char_vector_push_back(CharVector* v, char item) {
    int flag = -1;
    if (v->size == v->capacity) {
        v->data = (char*)realloc(v->data, v->size*2);
        if (v->data != NULL) {
            v->data[v->size] = item;
            v->capacity = v->size*2;
            flag = 0;
        }else {
            flag = -1;
        }
        
    }else {
        v->data[v->size] = item;
        flag = 0;
    }
    v->size++;
    return flag;
}
