#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void input(CharVector* vector, FILE* string)
{
    char b;
    while ((b = fgetc(string)) != EOF) {
        if (b != '\n') {
            char_vector_push_back(vector, b);
        }
    }
}

void output(CharVector* vector, CharVector* cpy_vector, int faults, time_t time)
{
    system("clear");
    for (int i = 0; i < cpy_vector->size - 1; i++) {
        if (vector->data[i] != cpy_vector->data[i]) {
            printf("\033[91m%c\033[91m", cpy_vector->data[i]);
        } else {
            printf("\033[92m%c\033[92m", cpy_vector->data[i]);
        }
    }
    printf("\n\n");
    printf("\033[39mTime of writting \033[91m%ld\033[39m seconds\n", time);
    printf("\033[39mYou've made \033[91m%d\033[39m mistakes!\n", faults);
}

int process(CharVector* vector, CharVector* vector_cpy, int* faults)
{
    char* words[vector->size];
    int count_of_words = stok(vector->data, ' ', words);
    time_t process_time_start = time(NULL);

    for (int i = 0; i < count_of_words; i++) {
        char ms[MAX_STRING_SIZE];
        char ms_cpy[strlen(words[i])];
        system("clear");
        printf("%s\n", words[i]);
        printf("\n");
        scanf("%s", ms);

        for (int u = 0; u <= strlen(words[i]); u++) {
            ms_cpy[u] = ms[u];
        }

        if ((strlen(ms_cpy) < strlen(words[i])) && (strcmp(ms_cpy, "~") != 0)) {
            for (int k = strlen(ms_cpy); k < strlen(words[i]); k++) {
                ms_cpy[k] = '_';
            }
        }

        for (int w = 0; w < strlen(words[i]); w++) {
            char_vector_push_back(vector_cpy, ms_cpy[w]);
        }
        char_vector_push_back(vector_cpy, ' ');

        if (strcmp(ms_cpy, "~") == 0) {
            time_t process_time_finish = time(NULL);
            vector_cpy->size = strlen(vector_cpy->data);
            unstok(vector->data, ' ', words, count_of_words);
            output(vector,
                   vector_cpy,
                   *faults,
                   (process_time_finish - process_time_start));
            char_vector_free(vector);
            char_vector_free(vector_cpy);
            return EARLY_TERMINATION_OF_THE_PROGRAM;
        }

        for (int j = 0; j < strlen(words[i]); j++) {
            if (words[i][j] != ms_cpy[j]) {
                (*faults) += 1;
            }
        }
    }
    system("clear");
    unstok(vector->data, ' ', words, count_of_words);
    return CORRECT_WORKING_OUT;
}
