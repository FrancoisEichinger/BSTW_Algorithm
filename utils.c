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

#include "utils.h"

long int file_size(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "file is not initialized\n");
        return -1;
    }

    if (fseek(file, 0, SEEK_END) < 0) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "Something went wrong while getting the end of the file\n");
        return -1;
    }

    //Limited by the ftell output
    long int size = ftell(file);

    if (fseek(file, 0, SEEK_SET) < 0) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "Something went wrong while going back at the beggining of the file\n");
        return -1;
    }

    return size;
}

char* codingArray(char* data)
{
    printf("\nENCODING STATES : \n");
	int i = 0;
	int j = 0;
    int letterCounter = 1;
	code = malloc(sizeof(char)*26); // + 1 = end char
	assert(code);
    char* result = malloc(sizeof(char)*2*strlen(data)+1);
    assert(result);


	for (int i = 0; i < 26; i++) {
		code[i] = 0;
	}
	while (data[i] != '\0')
	{
		if((data[i]>='a' && data[i]<='z') || (data[i]>='A' && data[i]<='Z'))
		{
			int found = -1;
            j = 0;
			while (code[j] != 0)
			{
				if(code[j] == data[i])
				{
					found = j;
					break;
				}
				j++;
			}
            if(found == -1)
            {
                char intToStr[4] = {0};
                sprintf(intToStr, "%d", letterCounter);
                char codeString[2] = {0};
                codeString[0] = data[i];
                result = strcat(result, strcat(intToStr, codeString));
                shiftEncode(data[i]);
                printf("%s\n", result);
                letterCounter++;
            }
			else
			{
                char isFound = code[found];
                code[found] = 0;
                shiftEncode(isFound);
                char intToStr[3] = {0};
                sprintf(intToStr, "%d", found+1);
                result = strcat(result, intToStr);
                printf("%s\n", result);
			}
		}
		i++;
	}
    return result;
}

void shiftEncode(char data)
{
    char saveChar = data;
    int j = 0;

    while(code[j] != 0)
    {
        char tmp = saveChar;
        saveChar = code[j];
        code[j++] = tmp;
    }


    code[j] = saveChar;
}

void shiftDecode(char data)
{
    char saveChar = data;
    int j = 0;

    while(decode[j] != 0)
    {
        char tmp = saveChar;
        saveChar = decode[j];
        decode[j++] = tmp;
    }
    decode[j] = saveChar;
}


char* decoding(char *data)
{
    printf("\nDECODING STATES : \n");
    int i = 0;
    char* result = malloc(sizeof(char)*strlen(data)+1);
    assert(result);
    decode = malloc(sizeof(char)*26); // + 1 = end char
	assert(decode);
    while(data[i] != 0)
    {
        if((data[i+1] >='a' && data[i+1]<='z') || (data[i+1]>='A' && data[i+1]<='Z'))
        {
            char codeString[2] = {0};
            codeString[0] = data[i+1];
            result = strcat(result, codeString);
            shiftDecode(data[i+1]);
            printf("%s\n", result);
            i++;
        }
        else
        {
            char codeString[2] = {0};
            codeString[0] = data[i];
            int charToInt = atoi(codeString) - 1;
            char isFound = decode[charToInt];
            decode[charToInt] = 0;




            shiftDecode(isFound);
            codeString[0] = isFound;
            result = strcat(result, codeString);
            printf("%s\n", result);
        }


        i++;
    }
    return result;
}
