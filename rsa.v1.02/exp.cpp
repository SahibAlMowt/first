#include "rsa.h"

int main()
{
    std::vector<sam_int> p;

    p = sam_input();

    ++p;

    sam_print(p);

    return 0;
}