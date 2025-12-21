#include <stdio.h>

int main()
{
    int a[50], size, i, key, found = 0;

    printf("enter size of an array \n");
    scanf("%d", &size);

    printf("enter elements of an array \n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter key \n");
    scanf("%d", &key);

    for (i = 0; i < size; i++)
    {
        if (key == a[i])
        {
            found = 1;
            printf("%d is found at a[%d]\n", key, i);
            break;
        }
    }

    if (found == 0)
    {
        printf("element not found \n");
    }

    return 0;
}