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
#define Set(a, s) memset(a, s, sizeof (a))

using namespace std;

int coin[]= {1,5,10,25,50};
int dp[6][7500];

int call(int i,int n)
{
    if(i>=5)
    {
        if(n==0) return 1;
        else return 0;
    }
    if(dp[i][n]!=-1) return dp[i][n];
    int ret1=0,ret2=0;
    if(n-coin[i]>=0) ret1=call(i,n-coin[i]);
    ret2=call(i+1,n);
    return dp[i][n]=ret1+ret2;
}

int main()
{
    int n;
    Set(dp,-1);
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",call(0,n));
    }
    return 0;
}


