#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int dp[1001][31];
int weight[1001];
int cost[1001];
int CAP;

int func(int i,int w)
{
    if(i==n+1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=CAP)
        profit1=cost[i]+func(i+1,w+weight[i]);
    profit2=func(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    int tc,g,sum;
    scanf("%d",&tc);
    while(tc--)
    {
        sum=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d\n",&cost[i],&weight[i]);
        }
        scanf("%d",&g);
        for(int i=1; i<=g; i++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&CAP);
            sum+=func(1,0);
        }
        printf("%d\n",sum);
    }
    return 0;
}
