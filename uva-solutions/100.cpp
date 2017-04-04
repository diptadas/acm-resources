#include <stdio.h>
void swap(long long int *a,long long int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    long long int i,j,a,b,n,x;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        printf("%lld %lld ",a,b);
        if(a>b) swap(&a,&b);
        x=0;
        for(j=a; j<=b; j++)
        {
            i=j;
            n=0;
            while(1)
            {
                n++;
                if(i==1) break;
                else if(i%2==0) i=i/2;
                else i=3*i+1;
            }
            if(n>x) x=n;
        }
        printf("%lld\n",x);
    }
    return 0;
}
