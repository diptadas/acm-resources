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
#define NN         1000009

bool flag[NN];
int primes[NN],total;
LL freq[NN];

void sieve()
{
    for(int i=4; i<NN; i+=2) flag[i]=1;

    for(int i=3; i*i<NN; i+=2)
    {
        if(flag[i]==0)
        {
            for(int j=i*i; j<NN; j+=2*i) flag[j]=1;
        }
    }

    total=0;

    for(int i=2; i<NN; i++)
        if(!flag[i]) primes[total++]=i;
}




int main()
{
    LL i,tc,u,l,ui,li;

    sieve();

    read(tc);

    while(tc--)
    {
        read(l);
        read(u);

        li=lower_bound(primes,primes+total,l)-primes;
        ui=lower_bound(primes,primes+total,u)-primes;

        if(primes[ui]!=u) ui--;

        LL mx=0,mxi,tmp=0,x;

        for(i=li; i<ui; i++)
        {
            x=primes[i+1]-primes[i];
            freq[x]++;
            if(freq[x]==mx) tmp=1;
            else if(freq[x]>mx)
            {
                mx=freq[x];
                mxi=x;
                tmp=0;
            }
        }

        if(mx==0 || tmp==1) printf("No jumping champion\n");
        else printf("The jumping champion is %lld\n",mxi);

        mset(freq,0);

    }

    return 0;
}
