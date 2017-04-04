#include <stdio.h>
#include <math.h>
int a[3001],b[3001];
int main()
{
    int n,d,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=0;
        }
        if(n==1) printf("Jolly\n");
        else
        {
            for(i=0,j=1; i<n-1; i++)
            {
                d=abs(a[i]-a[i+1]);
                if(d<1 || d>n-1 ||b[d]==1)
                {
                    j=0;
                    break;
                }
                b[d]=1;
            }
            if(j) printf("Jolly\n");
            else printf("Not jolly\n");
        }
    }
    return 0;
}
