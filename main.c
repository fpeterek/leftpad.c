#include <stdio.h>
#include <stdlib.h>

#include "fpmalloc.h"
#include "leftpad.h"


void test_malloc() {
    int* mem = fpmalloc(4096);

    if (mem == NULL) {
        puts("Null");
        exit(-1);
    }

    printf("%p\n", mem);

    size_t size = 4096 / sizeof(int);


    for (size_t i = 0; i < size; ++i) {
        mem[i] = (int)i;
    }

    printf("[%d]: %d\n", 0, mem[0]);
    printf("[%d]: %d\n", 500, mem[500]);
    printf("[%d]: %d\n", 1000, mem[1000]);

    fpfree(mem);
}


int main() {
    char padded[256] = "*********************************************";
    leftpad("abcd", '.', 8, padded, 5);

    puts(padded);

    leftpad("abcd", '.', 8, padded, 9);

    puts(padded);

    char* p = leftpad_a("str", '.', 10);

    puts(p);

    fpfree(p);
}
