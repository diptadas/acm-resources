#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 1000001

bool prime[max];
int primelist[max];
int maxdiv[max];

void sieve()
{
    long long i,j;
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    for(i=4; i<max; i+=2)
        prime[i]=1;
    for(i=3; i*i<max; i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<max; j+=2*i)
                prime[j]=1;
        }
    }
    for(i=1,j=0; i<max; i++)
    {
        if(!prime[i]) primelist[j++]=i;
    }
}

int div(int n)
{
    int i=0,j=0,count,ans=1,r=sqrt(n);
    while(primelist[i]<=r && n!=1)
    {
        count=0;
        while(n%primelist[i]==0)
        {
            count++;
            n=n/primelist[i];
        }
        ans*=count+1;
        i++;
    }
    if(n>1)
    {
        ans*=2;
    }
    return ans;
}
int main()
{
    int i,j,h,hn,t,n;
    sieve();
    for(i=1,h=0,hn=0; i<max; i++)
    {
        j=div(i);
        if(j>=h)
        {
            maxdiv[i]=i;
            hn=i;
            h=j;
        }
        else maxdiv[i]=hn;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",maxdiv[n]);
    }
    return 0;
}

