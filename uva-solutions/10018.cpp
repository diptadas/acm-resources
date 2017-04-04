#include <stdio.h>

long long unsigned rev(long long unsigned n)
{
    long long unsigned x=0;
    while (n!=0)
    {
          x=x*10+(n%10);
          n/=10;
    }
    return x;
}

int main()
{
    int tc,t,i;
    long long unsigned a,b;
    scanf("%d",&tc);
    for(t=0; t<tc; t++)
    {
        scanf("%llu",&a);
        a=a+rev(a);
        for(i=1;; i++)
        {
            b=rev(a);
            if(a==b) break;
            a=a+b;
        }
        printf("%d %llu\n",i,a);
    }
    return 0;
}
