#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

int n,l,walk,a[11][11],taken[11];
vector<int> result;

void call(int i,int k)
{
    if(k==l)
    {
        walk=1;
        printf("(1");
        for(int i=0; i<l; i++)
            printf(",%d",result[i]+1);
        puts(")");
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(taken[j]==0 && a[i][j]==1)
        {
            taken[j]=1;
            result.push_back(j);
            call(j,k+1);
            taken[j]=0;
            result.pop_back();
        }
    }
}

int main()
{
    int tmp;
    while(1)
    {
        memset(taken,0,sizeof(taken));
        result.clear();
        walk=0;
        cin>>n>>l;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) cin>>a[i][j];
        }
        taken[0]=1;
        call(0,0);
        if(!walk) printf("no walk of length %d\n", l);
        if(scanf("%d",&tmp)==EOF) break;
        else puts("");
    }
    return 0;
}

