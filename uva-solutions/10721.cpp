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
#include <list>
#include <set>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Mod 100000007
#define INF 0x7fffffff
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

LL dp[55][55];
int n,k,m;

LL call(int ni,int ki)
{
    if(ni==0 && ki==0) return 1;
    if(ni==0 || ki==0) return 0;
    if(dp[ni][ki]!=-1) return dp[ni][ki];
    LL ret=0;
    for(int i=1;i<=m && i<=ni;i++) ret+=call(ni-i,ki-1);
    return dp[ni][ki]=ret;
}

int main()
{
    while(scanf("%d %d %d",&n,&k,&m)==3)
    {
        mset(dp,-1);
        cout<<call(n,k)<<endl;
    }
    return 0;
}

