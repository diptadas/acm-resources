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

int a[10001],x;

int bin(int low,int hi)
{
    if(low>hi) return -1;
    int mid=(low+hi)/2;
    if(a[mid]==x) return mid;
    if(x>a[mid]) bin(mid+1,hi);
    else bin(low,mid-1);
}

int main()
{
    int n,q,cs=0;
    while(scanf("%d %d",&n,&q) && (n||q))
    {
        printf("CASE# %d:\n",++cs);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&x);
            int t=bin(0,n-1);
            if(t==-1) printf("%d not found\n",x);
            else
            {
                while(t!=0 && a[t-1]==x) t--;
                printf("%d found at %d\n",x,t+1);
            }
        }
    }
    return 0;
}

