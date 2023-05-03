#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lib/char_vector.h>
#include <lib/library.h>

int main()
{
    FILE* string = NULL;

    srand(time(NULL));
    int random_num_of_future_text = 1 + rand() % 10;

    printf("Choose a type of text:\n1)regular\n2)text for practicing "
           "combinations\n");
    char type = getchar();
    int tmp1 = get_type_of_text(type);
    if (tmp1 == NOT_NUMBER) {
        printf("Error\nYou wrote not a number!\n");
        return CORRECT_WORKING_OUT;
    }

    string = opening_file(string, tmp1, random_num_of_future_text);
    if (string == NULL) {
        printf("You write not a 1 or 2!\n");
        return CORRECT_WORKING_OUT;
    }

    CharVector* vector = char_vector_new(2);
    CharVector* cpy_vector = char_vector_new(2);

    input(vector, cpy_vector, string);

    int faults = CORRECT_WORKING_OUT;

    int tmp2 = process(vector, cpy_vector, &faults);
    if (tmp2 == EARLY_TERMINATION_OF_THE_PROGRAM) {
        fclose(string);
        return CORRECT_WORKING_OUT;
    }

    output(vector, cpy_vector, faults);

    char_vector_free(vector);
    char_vector_free(cpy_vector);
    fclose(string);
}