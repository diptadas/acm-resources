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
#define NN         1001

LL phi(LL n)
{
    LL ret=n;
    for (LL i=2; i*i<= n; i++)
    {
        if (n%i==0)
        {
            while(n%i==0) n/=i;
            ret-=ret/i;
        }
    }
    if(n>1) ret-=ret/n;
    return ret;
}


int main()
{
    LL i,j,k,n;

    while(read(n) && n)
    {
        if(n==1) puts("0");
        else printf("%lld\n",phi(n));
    }
    return 0;
}
