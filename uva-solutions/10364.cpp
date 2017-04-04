//Dipta Das CUET CSE-11

#include <bits/stdc++.h>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Mod 100000007
#define Inf 0x7fffffff
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int n,av,h[21],dp[1<<20];

int call(int x,int sum,int mask)
{
    if(sum==av)
    {
        sum=0;
        x++;
    }
    if(mask==(1<<n)-1)
    {
        if(x==4) return 1;
        return 0;
    }
    if(dp[mask]!=-1) return dp[mask];

    for(int i=0; i<n; i++)
    {
        if((mask&(1<<i))==0 && h[i]+sum<=av)
        {
            int ret=call(x,sum+h[i],mask|(1<<i));
            if(ret==1) return dp[mask]=1;
        }
    }
    return dp[mask]=0;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        mset(dp,-1);
        scanf("%d",&n);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&h[i]);
            sum+=h[i];
        }
        if(sum%4) cout<<"no\n";
        else
        {
            av=sum/4;
            if(call(0,0,0)) cout<<"yes\n";
            else cout<<"no\n";
        }
    }
    return 0;
}

