# leftpad.c

Leftpad, but without NPM, because, unlike JS "programmers", we are not mentally deranged.

Doesn't depend directly on libc or any other library, but requires a functional Linux kernel and GCC.

## Build

```sh
gcc syscalls.s fpmalloc.c fpstring.c fpwrite.c leftpad.c main.c -std=gnu23 -Wall -Wextra -Wconversion -nostdlib -fno-stack-protector -o main
```
