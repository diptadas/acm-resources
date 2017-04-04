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

void sieve()
{
    flag[0]=flag[1]=1;
    for(int i=4; i<NN; i+=2) flag[i]=1;

    for(int i=3; i*i<NN; i+=2)
    {
        if(flag[i]==0)
        {
            for(int j=i*i; j<NN; j+=2*i) flag[j]=1;
        }
    }
}

LL rev(LL n)
{
    LL ret=0,tmp=0;
    while(n)
    {
        if(n%10 || tmp)
        {
            ret=(ret*10)+(n%10);
            tmp=1;
        }
        n/=10;
    }
    return ret;
}


int main()
{
    LL i,j,k,n,r;

    sieve();

    while(read(n)!=EOF)
    {
        r=rev(n);
        printf("%lld is ",n);
        if(flag[n]) puts("not prime.");
        else if(r==n || flag[r]) puts("prime.");
        else puts("emirp.");
    }
    return 0;
}
