#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/char_vector.h>
#include <lib/library.h>

int stok(char* src, char symb, char** strs)
{
    int i = 0;
    int numstrs = 1;
    strs[i] = src;
    while (src[i] != '\0') {
        if (src[i] == symb) {
            src[i] = '\0';
            strs[numstrs] = &(src[i]) + 1;
            numstrs++;
        }
        i++;
    }
    return numstrs;
}

void unstok(char* str, char delim, char** ptr, int cnt)
{
    for (int i = 1; i < cnt; i++) {
        *(ptr[i] - 1) = delim;
    }
}

int get_type_of_text(char type)
{
    if (isdigit(type) == 0) {
        return NOT_NUMBER;
    } else {
        return ((int)type) - 48;
    }
}

FILE* opening_file(FILE* string, int type, int random_num_of_future_text)
{
    if (type == 1) {
        switch (random_num_of_future_text) {
        case 1:
            string = fopen("texts/ENG/eng1.txt", "r");
            break;
        case 2:
            string = fopen("texts/ENG/eng2.txt", "r");
            break;
        case 3:
            string = fopen("texts/ENG/eng3.txt", "r");
            break;
        case 4:
            string = fopen("texts/ENG/eng4.txt", "r");
            break;
        case 5:
            string = fopen("texts/ENG/eng5.txt", "r");
            break;
        case 6:
            string = fopen("texts/ENG/eng6.txt", "r");
            break;
        case 7:
            string = fopen("texts/ENG/eng7.txt", "r");
            break;
        case 8:
            string = fopen("texts/ENG/eng8.txt", "r");
            break;
        case 9:
            string = fopen("texts/ENG/eng9.txt", "r");
            break;
        case 10:
            string = fopen("texts/ENG/eng10.txt", "r");
            break;
        }
    } else if (type == 2) {
        switch (random_num_of_future_text) {
        case 1:
            string = fopen("texts/SpecTexts/spc1.txt", "r");
            break;
        case 2:
            string = fopen("texts/SpecTexts/spc2.txt", "r");
            break;
        case 3:
            string = fopen("texts/SpecTexts/spc3.txt", "r");
            break;
        case 4:
            string = fopen("texts/SpecTexts/spc4.txt", "r");
            break;
        case 5:
            string = fopen("texts/SpecTexts/spc5.txt", "r");
            break;
        case 6:
            string = fopen("texts/SpecTexts/spc6.txt", "r");
            break;
        case 7:
            string = fopen("texts/SpecTexts/spc7.txt", "r");
            break;
        case 8:
            string = fopen("texts/SpecTexts/spc8.txt", "r");
            break;
        case 9:
            string = fopen("texts/SpecTexts/spc9.txt", "r");
            break;
        case 10:
            string = fopen("texts/SpecTexts/spc10.txt", "r");
            break;
        }
    } else {
        return NULL;
    }
    return string;
}

int input(CharVector* vector, CharVector* cpy_vector, FILE* string)
{
    char b;
    int tmp = 0;
    while ((b = fgetc(string)) != EOF) {
        if (b != '\n') {
            tmp += char_vector_push_back(vector, b);
        }
    }
    for (int i = 0; i < vector->size; i++) {
        tmp += char_vector_push_back(cpy_vector, vector->data[i]);
    }
    return tmp;
}

void output(CharVector* vector, CharVector* cpy_vector, int faults)
{
    system("clear");
    for (int i = 0; i <= vector->size; i++) {
        if (vector->data[i] != cpy_vector->data[i]) {
            printf("\033[91m%c\033[91m", cpy_vector->data[i]);
        } else {
            printf("\033[92m%c\033[92m", cpy_vector->data[i]);
        }
    }
    printf("\n\n");
    printf("\033[39mYou was make a \033[91m%d\033[39m faults!\n", faults);
}

int process(CharVector* vector, CharVector* cpy_vector, int* faults)
{
    int count = 0;
    char* words[vector->size];
    int count_of_words = stok(vector->data, ' ', words);

    char* words_cpy[vector->size];
    stok(cpy_vector->data, ' ', words_cpy);

    for (int i = 0; i < count_of_words; i++) {
        for (int r = 0; r < strlen(words[i]); r++) {
            words_cpy[i][r] = ' ';
        }
        char ms[MAX_STRING_SIZE];
        char ms_cpy[strlen(words[i])];

        system("clear");
        printf("%s\n", words[i]);
        scanf("%s", ms);

        for (int u = 0; u <= strlen(words[i]); u++) {
            ms_cpy[u] = ms[u];
        }

        count += strlen(words[i]);

        if (strcmp(ms_cpy, "~") == 0) {
            printf("%d\n", *faults);
            vector->size = count;
            unstok(vector->data, ' ', words, count_of_words);
            unstok(cpy_vector->data, ' ', words_cpy, count_of_words);
            output(vector, cpy_vector, *faults);
            char_vector_free(vector);
            char_vector_free(cpy_vector);
            return EARLY_TERMINATION_OF_THE_PROGRAM;
        }

        for (int j = 0; j < strlen(words[i]); j++) {
            if (words[i][j] != ms_cpy[j]) {
                (*faults) += 1;
            }
        }

        if (strlen(ms_cpy) < strlen(words[i])) {
            for (int k = strlen(ms_cpy); k < strlen(words[i]); k++) {
                ms_cpy[k] = '_';
            }
        }
        strcpy(words_cpy[i], ms_cpy);
    }
    system("clear");
    unstok(vector->data, ' ', words, count_of_words);
    unstok(cpy_vector->data, ' ', words_cpy, count_of_words);
    return CORRECT_WORKING_OUT;
}