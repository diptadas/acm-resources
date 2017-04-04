#include <stdio.h>
int main()
{
    int t,i,j,n,a[101];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[j]);
        }
        printf("Case %d: %d\n",i+1,a[n/2]);
    }
    return 0;
}
