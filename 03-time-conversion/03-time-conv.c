#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

char* timeConversion(char* s)
{
    int hour = (s[0] - '0') * 10 + (s[1] - '0');

    if (s[8] == 'A')
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    s[0] = (hour / 10) + '0';
    s[1] = (hour % 10) + '0';

    s[8] = '\0';

    return s;
}

int main()
{
    char* s = readline();

    char* result = timeConversion(s);

    printf("%s\n", result);

    free(s);

    return 0;
}

char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true)
    {
        char* cursor = data + data_length;

        char* line = fgets(
            cursor,
            alloc_length - data_length,
            stdin
        );

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 ||
            data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length *= 2;

        data = realloc(data, alloc_length);

        if (!data)
        {
            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
    }
    else
    {
        data = realloc(data, data_length + 1);
        data[data_length] = '\0';
    }

    return data;
}