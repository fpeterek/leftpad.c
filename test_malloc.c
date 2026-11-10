#include <stdio.h>

#include "fpexit.h"
#include "fpmalloc.h"
#include "fpwrite.h"


int main() {
    int* mem = fpmalloc(4096);

    if (mem == NULL) {
        fpputs("Null");
        fpexit(-1);
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
