#include <stdio.h>
int main()
{
    int tc,n,i,j,k,temp,a[51],count;
    scanf("%d",&tc);

    for(k=0; k<tc; k++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0,count=0; i<n; i++)
        {
            for(j=0; j<n-i-1; j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}

