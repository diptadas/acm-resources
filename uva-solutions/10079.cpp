#include<stdio.h>
int main()
{
    long long int n,i,a,b;
    while(scanf("%lld",&n)==1 && (n>=0))
    {
        for(i=0,a=1; i<=n; i++)
        {
            b=a+i;
            a=b;
        }
        printf("%lld\n",b);
    }

    return 0;
}
