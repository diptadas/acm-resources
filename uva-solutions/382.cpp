#include <stdio.h>
int main ()
{
    int n,d,s;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n) && n!=0)
    {
        for(d=n/2,s=0; d>0; d--)
        {
            if(n%d==0)
            {
                s+=d;
            }
        }
        if(s==n) printf("%5d  PERFECT\n",n);
        else if(s<n) printf("%5d  DEFICIENT\n",n);
        else printf("%5d  ABUNDANT\n",n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
