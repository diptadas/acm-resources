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
#define NN         1500

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

    for(int i=1; i<NN; i++) //include 1
        if(!flag[i]) primes[total++]=i;
}




int main()
{

    LL i,j,k,n,c;

    sieve();

    while(scanf("%lld %lld",&n,&c)==2)
    {
        printf("%lld %lld:",n,c);

        for(i=0; primes[i]<=n; i++) ;

        if(i%2) c=2*c-1;
        else c=2*c;

        j=(i-c)/2;

        if(j<0)
        {
            j=0;
            c=i;
        }

        while(c)
        {
            printf(" %lld",primes[j]);
            j++;
            c--;
        }

        puts("\n");
    }
    return 0;
}
