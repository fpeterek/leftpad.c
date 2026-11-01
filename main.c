#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>



void* fpmmap(size_t size);
void fpmunmap(void* addr, size_t size);


int main() {
    int* mem = fpmmap(4096);

    if (mem == NULL) {
        puts("Null");
        return -1;
    }

    if (mem == (int*)-1) {
        puts("Mmap failed");
        return -1;
    }

    printf("errno: %d\n", errno);

    printf("%p\n", mem);

    size_t size = 4096 / sizeof(int);

    EACCES;

    MAP_FAILED;

    // for (size_t i = 0; i < size; ++i) {
    //     mem[i] = (int)i;
    // }

    printf("[%d]: %d\n", 0, mem[0]);
    // printf("[%d]: %d\n", 1000, mem[1000]);
    // printf("[%d]: %d\n", 2000, mem[2000]);
    // printf("[%d]: %d\n", 3000, mem[3000]);
    // printf("[%d]: %d\n", 4000, mem[4000]);
    // printf("[%d]: %d\n", 4095, mem[4095]);
}
