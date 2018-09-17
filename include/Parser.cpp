// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#include <cstdio>
#include "Parser.h"

int getWordLength(const char *c, const char *e)
{
    int wordLength = 0;
    while ((c < e) && (*c != ' ') && (*c != '\n'))
    {
        c++;
        wordLength++;
    }
    return wordLength;
}

float getFloat(const char *&c, const char *e)
{
    float f;
    sscanf(c, "%f", &f);
    c += getWordLength(c, e);
    return f;
}
