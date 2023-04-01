#include <stdio.h>

int main(void)
{
    int sum = 0;
    int n;
    printf("Nhap n = "); scanf("%d",&n);
    while (n != 0)
    {
        if(n % 2  == 0)
        {
            sum = sum + n % 10;
            
        }
        n = n/10;

    }
    printf("\nTong cac so chan la %d: ",sum);

    return 0;
}

