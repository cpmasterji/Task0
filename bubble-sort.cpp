#include<stdio.h>
int main()
{
    int a[1000], i, n, temp, no;
    printf("enter the number of elements in your array which you want to sort(natural number):");
    scanf("%d", &n);
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("Enter the %d th element in the array:", i + 1);
            scanf("%d", &a[i]);
        }
        for (no = 0; no < n - 1; no++)
        {
            for (i = 0; i < n - 1; i++)
            {
                if (a[i] > a[i + 1])
                {
                    temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                }
            }
        }
        printf("After sorting in ascending order:");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else
    {
        printf("enter correct details");
    }
}
