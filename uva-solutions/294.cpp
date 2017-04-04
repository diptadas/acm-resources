//Dipta Das CUET CSE-11

#include <bits/stdc++.h>
using namespace std;

#define LL         long long
#define pll        pair<LL,LL>
#define mp         make_pair
#define fr         first
#define sc         second
#define pb         push_back

#define read(n)    scanf("%lld",&n)
#define mset(a,s)  memset(a,s,sizeof(a))
#define all(a)     a.begin(),a.end()

#define PI         acos(-1.0)
#define EPS        1e-7
#define MOD        1000000007
#define INF        1e9
#define NN         32000

bool flag[NN];
LL primes[NN],total;

void sieve()
{
    for(LL i=4; i<NN; i+=2) flag[i]=1;

    for(LL i=3; i*i<NN; i+=2)
    {
        if(flag[i]==0)
        {
            for(LL j=i*i; j<NN; j+=2*i) flag[j]=1;
        }
    }

    total=0;

	for(LL i=2; i<NN; i++)
		if(!flag[i]) primes[total++]=i;
}


LL no_of_divisor(LL n)
{
    LL i,cnt,ans=1;

    for(i=0; i<total && primes[i]*primes[i]<=n && n!=1; i++)
    {
        if(n%primes[i]==0)
        {
            cnt=0;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }

    if(n>1) ans*=2;

    return ans;
}


int main()
{
    LL i,j,k,l,u,tc,mx,mxi;

    sieve();

    read(tc);

    while(tc--)
    {
        read(l);
        read(u);
        mx=0;
        for(i=l;i<=u;i++)
        {
            k=no_of_divisor(i);
            if(k>mx)
            {
                mx=k;
                mxi=i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,mxi,mx);
    }
    return 0;
}
