#include <stdio.h>

long long int f91(long long int n)
{
    if (n<=100) return f91(f91(n+11));
    if (n>=101) return(n-10);
}

int main()
{
    long long int n,a;
    while(scanf("%lld",&n)==1 && n!=0)
    {
        printf("f91(%lld) = %lld\n",n,f91(n));
    }

    return 0;
}
