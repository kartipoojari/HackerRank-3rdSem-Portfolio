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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(int arr_rows, int arr_columns, int** arr)
{
    int leftDiagonal = 0;
    int rightDiagonal = 0;

    for (int i = 0; i < arr_rows; i++)
    {
        leftDiagonal += arr[i][i];
        rightDiagonal += arr[i][arr_columns - 1 - i];
    }

    return abs(leftDiagonal - rightDiagonal);
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    int** arr = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(n * sizeof(int));

        char** arr_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++)
        {
            arr[i][j] = parse_int(arr_item_temp[j]);
        }
    }

    int result = diagonalDifference(n, n, arr);

    printf("%d\n", result);

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
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
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

char* ltrim(char* str)
{
    if (!str)
    {
        return NULL;
    }

    while (isspace(*str))
    {
        str++;
    }

    return str;
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
        splits = realloc(splits, sizeof(char*) * (spaces + 1));
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