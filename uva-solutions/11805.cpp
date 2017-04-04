#include <stdio.h>
int main()
{
    int t,n,k,p,i,j;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d",&n,&k,&p);
        for(j=0; j<p; j++)
        {
            if(k==n) k=1;
            else k++;
        }
        printf("Case %d: %d\n",i+1,k);
    }
    return 0;
}
