#ifndef FPWRITE_H
#define FPWRITE_H

#include "intdef.h"


ssize fpwrite(int fd, const void* data, usize size);

ssize fpputs(const char* str);


#endif  // FPWRITE_H
