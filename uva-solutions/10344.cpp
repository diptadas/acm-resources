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

int p,a[5];

void call(int n,int sum)
{
    if(p) return;

    if(n==5)
    {
        if(sum==23) p=1;
        return;
    }

    for(int i=0; i<3; i++)
    {
        if(i==0) call(n+1,sum+a[n]);
        else if(i==1) call(n+1,sum-a[n]);
        else call(n+1,sum*a[n]);
    }
}

int main()
{
    while(1)
    {
        p=0;
        int t=0;
        for(int i=0; i<5; i++)
        {
            cin>>a[i];
            t+=a[i];
        }
        if(t==0) break;

        sort(a,a+5);

        do
        {
            call(2,a[0]+a[1]);
            call(2,a[0]-a[1]);
            call(2,a[0]*a[1]);
            if(p) break;
        }
        while(next_permutation(a,a+5));

        if(p) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}

