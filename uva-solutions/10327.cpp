#include <stdio.h>
int main()
{
    int n,m,i,j,temp,a[1000];
    while(scanf("%d",&n)!= EOF)
    {
        m=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]>a[j]) m++;
            }
        }
        printf("Minimum exchange operations : %d\n",m);
    }
    return 0;
}
