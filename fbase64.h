#ifndef FBASE64_H
#define FBASE64_H

#include <stdio.h>

void base64_encode(FILE* ofile, FILE* ifile);

void base64_decode(FILE* ofile, FILE* ifile);

#endif

