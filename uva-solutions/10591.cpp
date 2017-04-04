#include <stdio.h>
int main()
{
    long long int n,m,x,sum;
    int i,t;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lld",&n);
        m=n;
        while(1)
        {
            sum=0;
            while(m)
            {
                x=m%10;
                sum+=(x*x);
                m=m/10;
            }
            m=sum;
            if(m==1 || m==4) break;
        }
        if(m==1) printf("Case #%d: %lld is a Happy number.\n",i+1,n);
        else if(m==4) printf("Case #%d: %lld is an Unhappy number.\n",i+1,n);
    }
    return 0;
}
