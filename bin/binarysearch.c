#include <stdio.h>

int main()
{
    int a[100], found = 0, low, high, mid, i, se, n;

    printf("enter no of elements\n");
    scanf("%d", &n);

    printf("enter elements in ascending order \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("enter search element \n");
    scanf("%d", &se);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (se == a[mid])
        {
            printf("search element is found at location a[%d]\n", mid);
            found = 1;
            break;
        }
        else if (se < a[mid])
        {
            high = mid - 1;
        }
        else if (se > a[mid])
        {
            low = mid + 1;
        }
    }

    if (found == 0)
    {
        printf("element not found \n");
    }

    return 0;
}