#include <stdio.h>
int main()
{
    int n,i,j,x,y,sum,t=0;
    while(scanf("%d",&n) && n!=0)
    {
        int a[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        printf("Case %d:",++t);
        for(x=0,y=n-1; x<=y; x++,y--)
        {
            sum=0;
            if(x==y) sum+=a[x][y];
            else
            {
                for(i=x; i<=y; i++) sum+=a[x][i]+a[y][i];
                for(i=x+1; i<=y-1; i++) sum+=a[i][x]+a[i][y];
            }
            printf(" %d",sum);
        }
        printf("\n");
    }
    return 0;
}
