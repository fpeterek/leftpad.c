#ifndef LEFTPAD_H
#define LEFTPAD_H

#include "fpmalloc.h"


char* leftpad_s(char* str, usize slen, char pchar, usize psize, char* dest, usize dsize);

char* leftpad(char* str, char pchar, usize psize, char* dest, usize dsize);

char* leftpad_a(char* str, char pchar, usize psize);

#endif // LEFTPAD_H
