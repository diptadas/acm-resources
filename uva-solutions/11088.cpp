//Dipta Das CUET CSE-11

#include <bits/stdc++.h>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Mod 100000007
#define Inf 0x7fffffff
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int n,a[20],dp[1<<16];

int call(int mask)
{
    if(dp[mask]!=-1) return dp[mask];
    int mx=0,ret;
    for(int i=0; i<n; i++)
    {
        if((mask&(1<<i))!=0) continue;
        for(int j=i+1; j<n; j++)
        {
            if((mask&(1<<j))!=0) continue;
            for(int k=j+1; k<n; k++)
            {
                if((mask&(1<<k))!=0 || (a[i]+a[j]+a[k])<20) continue;
                ret=call(((mask|(1<<i))|(1<<j))|(1<<k))+1;
                mx=max(mx,ret);
            }
        }
    }
    return dp[mask]=mx;
}

int main()
{
    int tc=0;
    while(scanf("%d",&n) && n!=0)
    {
        tc++;
        mset(dp,-1);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        if(n<3) printf("Case %d: 0\n",tc);
        else printf("Case %d: %d\n",tc,call(0));
    }
    return 0;
}

