#include <stdio.h>
gcd(int a,int b)
{
    int t=1;
    while(t)
    {
        t=b%a;
        b=a;
        a=t;
    }
    return b;
}
int main()
{
    int n,i,j;
    long long int g;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        g=0;
        for(i=1; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                g=g+gcd(i,j);
            }
        }
        printf("%lld\n",g);
    }
    return 0;
}
