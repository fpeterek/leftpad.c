#include "fpmalloc.h"


typedef struct {
    usize size;
    // Make sure memory is aligned to 16 bytes
    char padding[8];
} Meta;


void* fpmalloc(usize size) {
    usize total_size = size + sizeof(Meta);
    void* mem = fpmmap(total_size);

    if (mem == nullptr || mem == (void*)-1) {
        return nullptr;
    }

    Meta* meta = (Meta*)mem;

    *meta = (Meta) {
        .size = total_size,
    };

    return mem + sizeof(Meta);
}


void* fpcalloc(usize items, usize item_size) {
    return fpmalloc(items * item_size);
}


void fpfree(void* mem) {
    void* begin = mem - sizeof(Meta);
    Meta* meta = (Meta*)begin;

    usize size = meta->size;

    fpmunmap(begin, size);
}

