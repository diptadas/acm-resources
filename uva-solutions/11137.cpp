//Dipta Das CUET CSE-11

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Mod 100000007
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

LL a[22],dp[22][10001];

LL call(int i,int n)
{
    if(a[i]>n || i>21)
    {
        if(n==0) return 1;
        return 0;
    }
    if(dp[i][n]!=-1) return dp[i][n];
    LL ret1=0,ret2=0;
    ret1=call(i,n-a[i]);
    ret2=call(i+1,n);
    return dp[i][n]=ret1+ret2;
}

int main()
{
    int n;
    mset(dp,-1);
    for(int i=0;i<=21;i++) a[i]=i*i*i;
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",call(1,n));
    }
    return 0;
}
