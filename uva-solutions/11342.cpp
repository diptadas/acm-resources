#include <stdio.h>
#include <math.h>

struct square
{
    int sum,a,b;
} sq[25200];

int main()
{
    int tc,n,i,j,k;

    scanf("%d",&tc);

    for(i=0,k=0; i<=223; i++)
    {
        for(j=i; j<=223; j++,k++)
        {
            sq[k].a=i;
            sq[k].b=j;
            sq[k].sum=(i*i)+(j*j);
        }
    }

    while(tc--)
    {
        scanf("%d",&n);
        for(i=0; i<25200; i++)
        {
            if(n>sq[i].sum)
            {
                j=n-sq[i].sum;
                k=sqrt(j);
                if(k*k==j)
                {
                    printf("%d %d %d\n",sq[i].a,sq[i].b,k);
                    break;
                }
            }
        }
        if(i==25200) printf("-1\n");
    }
    return 0;
}

