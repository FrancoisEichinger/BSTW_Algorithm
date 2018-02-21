/*
** @author: Copyright (C) Francois Eichinger
** HEPIA 2018
** This program is free software, you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/

#ifndef UTILS_H
#define UTILS_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

char* code;
char* decode;

char* codingArray(char* data);

long int file_size(FILE *file);

void shiftEncode(char data);

void shiftDecode(char data);

char* decoding(char *data);

#endif
