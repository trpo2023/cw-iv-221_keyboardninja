#define CTEST_MAIN
#define CTEST_COLOR_OK
#define CTEST_SEGFAULT

#include <ctest.h>

#include <lib/char_vector.h>
#include <lib/library.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}