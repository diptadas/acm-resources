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
#define INF        1e18
#define NN         1000009

bool flag[NN];
LL primes[NN],total;
double sum[NN];

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

LL get(LL n,LL p)
{
    LL sum=0;
    while(n)
    {
        sum+=n/p;
        n/=p;
    }
    return sum;
}

LL trailing_zero_base_b(LL n,LL b)
{
    LL i,ans,cnt,power;
    ans=INF;
    for(i=0; primes[i]*primes[i]<=b && b!=1; i++)
    {
        if(b%primes[i]==0)
        {
            cnt=0;
            while(b%primes[i]==0)
            {
                cnt++;
                b/=primes[i];
            }
            power=get(n,primes[i]);
            ans=min(ans,power/cnt);
        }
    }
    if(b>1)
    {
        power=get(n,b);
        ans=min(ans,power);
    }
    return ans;
}


int main()
{
    LL i,n,b,ans,ans2;

    sieve();

    for(i=1; i<NN; i++) sum[i]=sum[i-1]+log(i*1.0);

    while(scanf("%lld %lld",&n,&b)==2)
    {
        ans=trailing_zero_base_b(n,b);
        ans2=1+(LL)(EPS+sum[n]/log(b*1.0));

        printf("%lld %lld\n",ans,ans2);
    }

    return 0;
}
