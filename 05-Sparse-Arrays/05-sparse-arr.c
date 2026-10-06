#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char strings[n][21];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", strings[i]);
    }

    int q;
    scanf("%d", &q);

    char query[21];

    for (int i = 0; i < q; i++)
    {
        scanf("%s", query);

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (strcmp(strings[j], query) == 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
