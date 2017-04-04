#include <stdio.h>

int main()
{
    long long int n,one,i,mod;
    while(scanf("%lld",&n)!=EOF)
    {
        i=one=mod=1;
        while(mod)
        {
            if(i<n)
            {
                i=(i*10)+1;
                one++;
            }
            mod=i%n;
            i=mod;
        }
        printf("%lld\n",one);
    }
    return 0;
}
