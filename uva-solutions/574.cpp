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

int taken[13],a[13],n,t,found,pre;
vector<int> result;

void call(int sum)
{
    if(sum>t) return;
    if(sum==t)
    {
        found=1;
        printf("%d",result[0]);
        for(int i=1; i<result.size(); i++)
            printf("+%d",result[i]);
        puts("");
        return;
    }

    pre=-1;
    for(int i=0; i<n; i++)
    {
        if(taken[i]==0 && a[i]!=pre && (result.size()==0 || a[i]<=result[result.size()-1]))
        {
            taken[i]=1;
            result.push_back(a[i]);
            call(sum+a[i]);
            taken[i]=0;
            pre=result.back();
            result.pop_back();
        }
    }
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    while(scanf("%d %d",&t,&n) && n!=0)
    {
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        memset(taken,0,sizeof(taken));
        result.clear();
        found=0;
        sort(a,a+n,cmp);
        printf("Sums of %d:\n",t);
        call(0);
        if(found==0) puts("NONE");
    }
    return 0;
}

