//
// Created by generalsuslik on 08.07.24.
//
// getline function
#include <stdio.h>

// set your default size
#define DEFAULT_SIZE 5000

int get_line(char line[], long lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) >= 0 && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}
