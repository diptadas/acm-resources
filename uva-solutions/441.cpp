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

int k;
int a[15];
int taken[15];
vector<int> result;

void call(int n)
{
    if(n==6)
    {
        printf("%d",result[0]);
        for(int i=1; i<6; i++)
            printf(" %d",result[i]);
        puts("");
        return;
    }

    for(int i=0; i<k; i++)
    {
        if(taken[i]==0)
        {
            if(result.size()==0 || result[result.size()-1]<a[i])
            {
                taken[i]=1;
                result.push_back(a[i]);
                call(n+1);
                taken[i]=0;
                result.pop_back();
            }
        }
    }
}

int main()
{
    int t=0;
    while(scanf("%d",&k) && k!=0)
    {
        if(t) puts("");
        t=1;
        memset(taken,0,sizeof(taken));
        result.clear();
        for(int i=0; i<k; i++) scanf("%d",&a[i]);
        call(0);
    }
    return 0;
}


