#include <stdio.h>
int main()
{
    int a[55],i,n,t=0,count,sum;
    while(scanf("%d",&n) && n!=0)
    {
        t++;
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sum=sum/n;
        for(i=0,count=0;i<n;i++)
        {
            if(a[i]>sum) count+=(a[i]-sum);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,count);
    }
}
