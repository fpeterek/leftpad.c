#include "fpstring.h"


usize string_len(const char* str) {
    usize len = 0;

    for (; str[len] != 0; ++len) { }

    return len;
}

