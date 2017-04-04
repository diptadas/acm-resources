#include <stdio.h>
#include <math.h>
#define max 18409205
using namespace std;

int prime[max/32];
int twin[100005];

bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int Set(int N,int pos)
{
    return (N | (1<<pos));
}

void bit_sieve()
{
    int i,j,k,r=sqrt(max);

    for( i=3; i <= r; i += 2 )
    {
        if( check(prime[i>>5],i&31)==0)
        {
            for( j = i*i; j <= max; j += 2*i )
            {
                prime[j>>5]=Set(prime[j>>5],j&31)   ;
            }
        }
    }
    for( i=3,j=5,k=0; i <= max; i += 2,j+=2 )
    {
        if( check(prime[i>>5],i&31)==0 && check(prime[j>>5],j&31)==0) twin[++k]=i;
    }
}

int main()
{
    int n;
    bit_sieve();
    while(scanf("%d",&n)==1)
    {
        printf("(%d, %d)\n",twin[n],twin[n]+2);
    }
    return 0;
}
