#include <stdio.h>
int main()
{
    long long int n,sum;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;
        while(n>9)
        {
            sum=0;
            while(n)
            {
                sum+=n%10;
                n=n/10;
            }
            n=sum;
        }
        printf("%d\n",n);
    }
    return 0;
}
