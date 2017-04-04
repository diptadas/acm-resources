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
string a,b;
int dp[61][61][61][61];

int call(int i,int j,int x,int y)
{
    if(i>j || x>y) return 0;
    if(dp[i][j][x][y]!=-1) return dp[i][j][x][y];

    int ret;

    if(a[i]==a[j]&&a[i]==b[x]&&b[x]==b[y])
    {
        if(i==j || x==y) ret=call(i+1,j-1,x+1,y-1)+1;
        else ret=call(i+1,j-1,x+1,y-1)+2;
    }

    else
    {
        int ret1=call(i+1,j,x,y);
        int ret2=call(i,j-1,x,y);
        int ret3=call(i,j,x+1,y);
        int ret4=call(i,j,x,y-1);
        ret =max(max(ret1,ret2),max(ret3,ret4));
    }

    return dp[i][j][x][y]=ret;
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        mset(dp,-1);
        cin>>a>>b;
        printf("Case %d: %d\n",t,call(0,a.size()-1,0,b.size()-1));
    }
    return 0;
}
