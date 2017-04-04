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
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int m,sum,a[101],dp[101][500500];

int call(int i,int s)
{
    if(i==m) return abs(sum-2*s);
    if(dp[i][s]!=-1) return dp[i][s];
    int ret1=call(i+1,s+a[i]);
    int ret2=call(i+1,s);
    return dp[i][s]=min(ret1,ret2);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        mset(dp,-1);
        scanf("%d",&m);
        sum=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        cout<<call(1,a[0])<<endl;
    }
    return 0;
}
