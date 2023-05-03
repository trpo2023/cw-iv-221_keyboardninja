#include <ctest.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/char_vector.h>
#include <lib/library.h>

CTEST(checknput, char_vector_new)
{
    CharVector* new1 = char_vector_new(12);
    CharVector* new2 = char_vector_new(12);
    CharVector* new3 = char_vector_new(12);
    CharVector* new4 = char_vector_new(12);
    CharVector* new5 = char_vector_new(12);

    ASSERT_NOT_NULL(new1);
    ASSERT_NOT_NULL(new2);
    ASSERT_NOT_NULL(new3);
    ASSERT_NOT_NULL(new4);
    ASSERT_NOT_NULL(new5);

    char_vector_free(new1);
    char_vector_free(new2);
    char_vector_free(new3);
    char_vector_free(new4);
    char_vector_free(new5);
}

CTEST(checknput, char_vector_push_back)
{
    CharVector* new1 = char_vector_new(12);
    CharVector* new2 = char_vector_new(12);
    CharVector* new3 = char_vector_new(12);
    CharVector* new4 = char_vector_new(12);
    CharVector* new5 = char_vector_new(12);

    const int expected = 0;

    ASSERT_NOT_NULL(new1);
    ASSERT_NOT_NULL(new2);
    ASSERT_NOT_NULL(new3);
    ASSERT_NOT_NULL(new4);
    ASSERT_NOT_NULL(new5);

    int vector1 = char_vector_push_back(new1, 45);
    int vector2 = char_vector_push_back(new2, 101);
    int vector3 = char_vector_push_back(new3, 77);
    int vector4 = char_vector_push_back(new4, 88);
    int vector5 = char_vector_push_back(new5, 89);

    ASSERT_EQUAL(vector1, expected);
    ASSERT_EQUAL(vector2, expected);
    ASSERT_EQUAL(vector3, expected);
    ASSERT_EQUAL(vector4, expected);
    ASSERT_EQUAL(vector5, expected);

    char_vector_free(new1);
    char_vector_free(new2);
    char_vector_free(new3);
    char_vector_free(new4);
    char_vector_free(new5);
}

CTEST(library, get_type_of_text)
{
    const int expected1 = NOT_NUMBER;
    const int expected2 = 0;
    const int expected3 = 1;
    const int expected4 = 2;
    const int expected5 = 3;

    int tmp1 = get_type_of_text('e');
    int tmp2 = get_type_of_text('0');
    int tmp3 = get_type_of_text('1');
    int tmp4 = get_type_of_text('2');
    int tmp5 = get_type_of_text('3');

    ASSERT_EQUAL(tmp1, expected1);
    ASSERT_EQUAL(tmp2, expected2);
    ASSERT_EQUAL(tmp3, expected3);
    ASSERT_EQUAL(tmp4, expected4);
    ASSERT_EQUAL(tmp5, expected5);
}

CTEST(library, opening_file)
{
    FILE* tmp1 = NULL;
    tmp1 = opening_file(tmp1, 2, 8);
    FILE* tmp2 = NULL;
    tmp2 = opening_file(tmp2, 2, 3);
    FILE* tmp3 = NULL;
    tmp3 = opening_file(tmp3, 2, 40);
    FILE* tmp4 = NULL;
    tmp4 = opening_file(tmp4, 10, 0);
    FILE* tmp5 = NULL;
    tmp5 = opening_file(tmp5, 1, 6);
    FILE* tmp6 = NULL;
    tmp6 = opening_file(tmp6, 123, 6);
    FILE* tmp7 = NULL;
    tmp7 = opening_file(tmp7, 1, 666);

    ASSERT_NOT_NULL(tmp1);
    ASSERT_NOT_NULL(tmp2);
    ASSERT_NOT_NULL(tmp5);
    ASSERT_NULL(tmp3);
    ASSERT_NULL(tmp4);
    ASSERT_NULL(tmp6);
    ASSERT_NULL(tmp7);
}