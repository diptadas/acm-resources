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

#define mx 1000001

vector<int> v;

int div(int n)
{
    int div=1;
    for(int i=2; i*i<=n; i++)
    {
        int s=0;
        while(n%i==0)
        {
            s++;
            n/=i;
        }
        div*=s+1;
    }
    if(n>1) div*=2;
    return div;
}

int bin1(int low,int hi,int n)
{
    if(low>hi) return -1;
    int mid=(low+hi)/2;
    if(v[mid]==n) return mid;
    if(n>v[mid]) bin1(mid+1,hi,n);
    else
    {
        if(n>v[mid-1]) return mid-1;
        bin1(low,mid-1,n);
    }
}

int bin2(int low,int hi,int n)
{
    if(low>hi) return -1;
    int mid=(low+hi)/2;
    if(v[mid]==n) return mid;
    if(n>v[mid])
    {
        if(n<v[mid+1]) return mid+1;
        bin2(mid+1,hi,n);
    }
    else bin2(low,mid-1,n);
}

int main()
{
    v.push_back(1);
    while(1)
    {
        int t=v.back();
        if(t>mx) break;
        v.push_back(t+div(t));
    }

    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",t,bin1(0,64725,b)-bin2(0,64725,a)+1);
    }
    return 0;
}

