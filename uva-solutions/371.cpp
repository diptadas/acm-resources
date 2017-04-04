#include <stdio.h>
int main()
{
    long long int i,j,t,x,y,n,s;
    while(scanf("%lld %lld",&i,&j))
    {
        if(i==0 && j==0) break;
        if(i>j)
        {
            t=i;
            i=j;
            j=t;
        }
        printf("Between %lld and %lld, ",i,j);
        for(x=i,y=0; i<=j; i++)
        {
            n=i;
            s=0;
            while(1)
            {
                if(n%2 == 0) n=n/2;
                else n=(3*n)+1;
                if(n==1)
                {
                    s++;
                    break;
                }
                s++;
            }
            if(s>y)
            {
                x=i;
                y=s;
            }
        }
        printf("%lld generates the longest sequence of %lld values.\n",x,y);
    }
    return 0;
}
