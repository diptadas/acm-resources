#include <stdio.h>
int main()
{
    int c,n,sum,count,i,a[1005];
    float ans;
    scanf("%d",&c);
    for(;c;c--)
    {
        scanf("%d",&n);
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sum=sum/n;
        for(i=0,count=0;i<n;i++)
        {
           if(a[i]>sum) count++;
        }
        ans=(float)(count*100)/(float)n;
        printf("%.3f%%\n",ans);
    }
    return 0;
}
