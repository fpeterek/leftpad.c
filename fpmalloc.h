#ifndef FP_MALLOC
#define FP_MALLOC

#include <stddef.h>


void* fpmmap(size_t size);
void fpmunmap(void* addr, size_t size);



#endif  // FP_MALLOC
