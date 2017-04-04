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

string prime="110010101110101110101110111110101";
int taken[17],n;
vector<int> result;

bool test(int i)
{
    int s=result.size();
    if(s==0) return prime[i+1]=='1';
    else if(s==n-2) return(prime[result[s-1]+i]=='1' || prime[i+1]=='1');
    else return prime[result[s-1]+i]=='1';
}

void call()
{
    if(result.size()==n-1)
    {
        printf("1");
        for(int i=0; i<result.size(); i++) printf(" %d",result[i]);
        puts("");
    }

    for(int i=2; i<=n; i++)
    {
        if(taken[i]==0 && test(i)==0)
        {

            taken[i]=1;
            result.push_back(i);
            call();
            taken[i]=0;
            result.pop_back();
        }
    }
}

int main()
{
    int cs=0;

    while(scanf("%d",&n)==1)
    {
        memset(taken,0,sizeof(taken));
        result.clear();
        if(cs) puts("");
        printf("Case %d:\n",++cs);
        call();
    }
    return 0;
}

