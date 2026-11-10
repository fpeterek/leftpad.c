#ifndef FP_MALLOC
#define FP_MALLOC

#include "intdef.h"


void* fpmmap(usize size);
void fpmunmap(void* addr, usize size);


void* fpmalloc(usize size);
void* fpcalloc(usize items, usize item_size);
void fpfree(void* mem);


#endif  // FP_MALLOC
