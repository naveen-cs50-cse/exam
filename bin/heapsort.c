#include <stdio.h>

int a[100], n;

void heapify(int i, int n)
{
    int j;
    j = (2 * i) + 1; 
    while (j < n)
    {
        if (j < n - 1)
        {
            if (a[j] < a[j + 1]) 
            {
                j++;
            }
        }
        if (a[i] < a[j]) 
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = (2 * i) + 1;
        }
        else
        {
            break;
        }
    }
}

void main()
{
    int i;
    printf("enter size of an array\n");
    scanf("%d", &n);

    printf("enter array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }


    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, n);
    }

    printf("Max Heap Elements are..... \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    for (i = n - 1; i >= 1; i--)
    {
        int temp = a[0]; 
        a[0] = a[i];
        a[i] = temp;
        heapify(0, i); 
    }

    printf("Heap Sort Elements are ..... \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}