#include "fpexit.h"
#include "fpmalloc.h"
#include "fpwrite.h"
#include "leftpad.h"



int main() {
    char padded[256] = "*********************************************";
    leftpad("abcd", '.', 8, padded, 5);

    fpputs(padded);

    leftpad("abcd", '.', 8, padded, 6);

    fpputs(padded);

    leftpad("abcd", '.', 8, padded, 9);

    fpputs(padded);

    char* p = leftpad_a("str", '.', 10);

    fpputs(p);

    fpfree(p);
}


void _start() {
    fpexit(main());
}

