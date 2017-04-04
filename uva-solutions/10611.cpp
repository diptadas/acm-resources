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

int bin(int low,int hi,int a[],int h)
{
    int mid=(low+hi)/2;
    if(a[mid]==h) return mid;
    if(h>a[mid])
    {
        if(h<a[mid+1]) return mid;
        bin(mid+1,hi,a,h);
    }
    else
    {
        if(h>a[mid-1]) return mid-1;
        bin(low,mid-1,a,h);
    }
}

int main()
{
    int n,q,h;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d",&h);
        int t=bin(0,n-1,a,h),x;

        x=t;
        if(a[x]<h) printf("%d ",a[x]);
        else
        {
            while(x!=-1 && a[x]>=h) x--;
            if(x==-1) printf("X ");
            else printf("%d ",a[x]);
        }

        x=t;
        if(a[x]>h) printf("%d",a[x]);
        else
        {
            while(x!=n && a[x]<=h) x++;
            if(x==n) printf("X");
            else printf("%d",a[x]);
        }
        puts("");
    }
    return 0;
}
