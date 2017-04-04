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
LL primes[NN],total;

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

    LL i,j,k,n;

    sieve();

    while(read(n)&& n!=0)
    {
        k=1;
        for(i=0;primes[i]<=n/2;i++)
        {
            if(flag[n-primes[i]]==0)
            {
                printf("%lld = %lld + %lld\n",n,primes[i],n-primes[i]);
                k=0;
                break;
            }
        }

        if(k) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
