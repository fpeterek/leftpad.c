#include "leftpad.h"

#include "fpstring.h"
#include "fpmalloc.h"


ssize smax(ssize x, ssize y) {
    if (x > y) {
        return x;
    }
    return y;
}

ssize smin(ssize x, ssize y) {
    if (x < y) {
        return x;
    }
    return y;
}

usize max(usize x, usize y) {
    if (x > y) {
        return x;
    }
    return y;
}

usize min(usize x, usize y) {
    if (x < y) {
        return x;
    }
    return y;
}


char* leftpad_s(char* str, usize slen, char pchar, usize psize, char* dest, usize dsize) {
    if (slen >= dsize) {
        return nullptr;
    } 

    usize avail = dsize - 1 - slen;

    usize padding_chars = (usize)smax((ssize)psize - (ssize)slen, 0);

    padding_chars = min(avail, padding_chars);

    usize i = 0;
    for (; i < padding_chars; ++i) {
        dest[i] = pchar;
    }

    for (;; ++str) {

        dest[i] = *str;

        if (*str == 0) {
            break;
        }

        ++i;
    }

    return dest;
}

char* leftpad(char* str, char pchar, usize psize, char* dest, usize dsize) {
    return leftpad_s(str, string_len(str), pchar, psize, dest, dsize);
}

char* leftpad_a(char* str, char pchar, usize psize) {
    usize len = string_len(str);
    usize req = len + 1 + psize;
    char* mem = fpmalloc(req * sizeof(char));

    return leftpad_s(str, len, pchar, psize, mem, req);
}
