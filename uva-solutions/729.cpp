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

int n,h,taken[17],a[17],pre;
vector<int> result;

void call()
{
    if(result.size()==n)
    {
        for(int i=0; i<n; i++) printf("%d",result[i]);
        puts("");
        return;
    }
    pre=-1;
    for(int i=0; i<n; i++)
    {
        if(taken[i]==0 && a[i]!=pre)
        {
            taken[i]=1;
            result.push_back(a[i]);
            call();
            taken[i]=0;
            pre=result.back();
            result.pop_back();
        }
    }
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(taken,0,sizeof(taken));
        memset(a,0,sizeof(a));
        result.clear();
        cin>>n>>h;
        for(int i=0; i<h; i++) a[n-i-1]=1;
        call();
        if(tc) puts("");
    }
    return 0;
}
