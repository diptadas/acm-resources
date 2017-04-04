#include <stdio.h>

long long int bigmod(long long int b,long long int p,long long int m)
{
    int temp;
    if(p==0) return 1;
    else if(p%2==0)
    {
        temp=bigmod(b,p/2,m);
        return (((temp%m)*(temp%m))%m);
    }
    else return (((bigmod(b,p-1,m)%m)*(b%m))%m);
}
int main()
{
    int long long base,pow,mod,ans,i;
    while(scanf("%lld %lld %lld",&base,&pow,&mod)!=EOF)
    {
        printf("%lld\n",bigmod(base,pow,mod));
    }
    return 0;
}

