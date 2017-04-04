#include <stdio.h>
#include <math.h>

int main()
{
    int n,i;

    while(scanf("%d",&n)&& n!=0)
    {
        if(n>0)  printf("%d = ",n);
        else
        {
            printf("%d = -1 x ",n);
            n*=-1;
        }

        for(i=2; i<=sqrt(n)&& n!=1; )
        {
            if(n%i==0)
            {
                printf("%d x ",i);
                n=n/i;
            }
            else if(i==2) i++;
            else i+=2;
        }
        printf("%d\n",n);
    }
    return 0;
}

