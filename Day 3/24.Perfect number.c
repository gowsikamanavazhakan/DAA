#include <stdio.h>

int main()
{
    int a, b, sum;
int end=1000;

    printf("All Perfect numbers between 1 to 1000 :");
    for(a=1; a<=end; a++)
    {
        sum = 0;
        for(b=1; b<a; b++)
        {
            if(a % b == 0)
            {
                sum += b;
            }
        }
        if(sum == a)
        {
            printf("%d ", a);
        }
    }

    return 0;
}

