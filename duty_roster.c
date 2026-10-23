```c
#include <stdio.h>

void rotateRoster(char names[][50], int n, int k)
{
    char temp[100][50];

    // Remove unnecessary full rotations
    k = k % n;

    // Move each name to its new position
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n][0] = '\0';

        int j = 0;
        while (names[i][j] != '\0')
        {
            temp[(i + k) % n][j] = names[i][j];
            j++;
        }

        temp[(i + k) % n][j] = '\0';
    }

    // Copy the rotated names back into the original array
    for (int i = 0; i < n; i++)
    {
        int j = 0;

        while (temp[i][j] != '\0')
        {
            names[i][j] = temp[i][j];
            j++;
        }

        names[i][j] = '\0';
    }
}
int main()
{
    char names[100][50];
    int n, k;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of names.\n");
        return 1;
    }

    printf("Enter the names:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%49s", names[i]);
    }

    printf("Enter the number of positions to rotate right: ");
    scanf("%d", &k);

    if (k < 0)
    {
        printf("Invalid rotation value.\n");
        return 1;
    }

    rotateRoster(names, n, k);

    printf("Rotated duty roster:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s", names[i]);

        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}
```
