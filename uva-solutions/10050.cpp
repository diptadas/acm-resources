#include <stdio.h>
int main()
{
    int a[101],i,j,n,p,t,tc,dl;
    scanf("%d",&tc);
    for(t=0; t<tc; t++)
    {
        scanf("%d %d",&n,&p);
        for(i=0; i<p; i++)
        {
            scanf("%d",&a[i]);
        }
        bool b[n+1];
        for(i=1; i<=n; i++)
        {
            b[i]=false;
        }
        for(i=0,dl=0; i<p; i++)
        {
            for(j=a[i]; j<=n; j+=a[i])
            {
                if((j%7)!=6 && (j%7)!=0 && b[j]!=true)
                {
                    b[j]=true;
                    dl++;
                }
            }
        }
        printf("%d\n",dl);
    }
}
