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
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

/*
 * To return the integer array from the function,
 * you should:
 *     - Store the results in a dynamically allocated array
 *     - Set the size of the returned array in *result_count
 */

int* dynamicArray(int n, int queries_rows, int queries_columns,
                  int** queries, int* result_count)
{
    int** seq = malloc(n * sizeof(int*));
    int* seqSize = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        seq[i] = NULL;
    }

    int lastAnswer = 0;

    int* result = malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++)
    {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1)
        {
            seqSize[index]++;

            seq[index] = realloc(
                seq[index],
                seqSize[index] * sizeof(int)
            );

            seq[index][seqSize[index] - 1] = y;
        }
        else if (type == 2)
        {
            int position = y % seqSize[index];

            lastAnswer = seq[index][position];

            result[*result_count] = lastAnswer;
            (*result_count)++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(seq[i]);
    }

    free(seq);
    free(seqSize);

    return result;
}

int main()
{
    FILE* fptr = stdout;

    char** first_multiple_input = split_string(
        rtrim(readline())
    );

    int n = parse_int(first_multiple_input[0]);
    int q = parse_int(first_multiple_input[1]);

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++)
    {
        queries[i] = malloc(3 * sizeof(int));

        char** queries_item_temp = split_string(
            rtrim(readline())
        );

        for (int j = 0; j < 3; j++)
        {
            queries[i][j] = parse_int(queries_item_temp[j]);
        }
    }

    int result_count;

    int* result = dynamicArray(
        n,
        q,
        3,
        queries,
        &result_count
    );

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", result[i]);

        if (i != result_count - 1)
        {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    for (int i = 0; i < q; i++)
    {
        free(queries[i]);
    }

    free(queries);
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