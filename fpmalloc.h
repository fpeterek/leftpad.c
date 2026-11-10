#ifndef FP_MALLOC
#define FP_MALLOC

typedef unsigned long long usize;
typedef long long ssize;


void* fpmmap(usize size);
void fpmunmap(void* addr, usize size);


void* fpmalloc(usize size);
void* fpcalloc(usize items, usize item_size);
void fpfree(void* mem);


#endif  // FP_MALLOC
