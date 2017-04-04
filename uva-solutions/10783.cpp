#include <stdio.h>
int main()
{
    int t,a,b,s,i,j;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);
        for(j=a,s=0; j<=b; j++)
        {
            if(j%2 !=0) s+=j;
        }
        printf("Case %d: %d\n",i,s);
    }
    return 0;
}
