#include "fpwrite.h"
#include "fpstring.h"


ssize fpputs(const char* str) {
    usize size = string_len(str);

    ssize res = fpwrite(1, str, size);

    if (res == -1ll) {
        return res;
    }

    res += fpwrite(1, "\n", 1);

    return res;
}

