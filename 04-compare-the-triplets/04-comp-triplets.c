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
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

/*
 * To return the integer array from the function,
 * you should:
 *     - Store the results in the array
 *     - Set the size in result_count
 */

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count)
{
    int alice = 0;
    int bob = 0;

    for (int i = 0; i < 3; i++)
    {
        if (a[i] > b[i])
        {
            alice++;
        }
        else if (a[i] < b[i])
        {
            bob++;
        }
    }

    int* result = malloc(2 * sizeof(int));

    result[0] = alice;
    result[1] = bob;

    *result_count = 2;

    return result;
}

int main()
{
    FILE* fptr = stdout;

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        a[i] = parse_int(a_temp[i]);
    }

    char** b_temp = split_string(rtrim(readline()));

    int* b = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        b[i] = parse_int(b_temp[i]);
    }

    int result_count;

    int* result = compareTriplets(
        3, a,
        3, b,
        &result_count
    );

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", result[i]);

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    free(a);
    free(b);
    free(result);

    fclose(fptr);

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

char* rtrim(char* str)
{
    if (!str)
    {
        return NULL;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str)
{
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while (token)
    {
        splits = realloc(
            splits,
            sizeof(char*) * (spaces + 1)
        );

        splits[spaces] = token;

        token = strtok(NULL, " ");
        spaces++;
    }

    return splits;
}

int parse_int(char* str)
{
    char* endptr;

    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}