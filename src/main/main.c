#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <lib/library.h>
#include <lib/char_vector.h>

int main()
{
    FILE* string;

    srand(time(NULL));
    int random_num_of_future_text = 1 + rand() % 10;

    printf("Choose a type of text:\n1)regular\n2)text for practicing "
           "combinations\n");
    char type = getchar();

    if (isdigit(type) == 0) {
        printf("Error\nYou wrote not a 1 or 2\n");
    }

    if (type == '1') {
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
    } else if (type == '2') {
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
        printf("you wrote not a digit\n");
        return -1;
    }

    if (string == NULL) {
        printf("Can't open a file!\n");
        return -1;
    }

    CharVector* vector = char_vector_new(2);
    CharVector* cpy_vector = char_vector_new(2);

    input(vector, cpy_vector, string);

    int faults = 0;

    int tmp = process(vector, cpy_vector, &faults);
    if (tmp == 1) {
        fclose(string);
        return 0;
    }

    output(vector, cpy_vector, faults);

    char_vector_free(vector);
    char_vector_free(cpy_vector);
    fclose(string);
}