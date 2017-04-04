#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

int pr[1000015];

struct edge
{
    int u,v,w;
    edge(int a,int b,int c)
    {
        u=a,v=b,w=c;
    }
    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

vector<edge> e;

int check(int r)
{
    return (pr[r]==r) ? r:  check(pr[r]);
}

int mst(int n)
{
    sort(e.begin(),e.end());

    for(int i=0; i<n; i++) pr[i]=i;

    int cnt=0,s=0;

    for(int i=0; i<e.size() && cnt<n-1; i++)
    {
        int u=check(e[i].u);
        int v=check(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            s+=e[i].w;
            cnt++;
        }
    }
    return s;
}

int main()
{
    int n,k,m,u,v,w,ans1,ans2,tmp=0;
    while(scanf("%d",&n)==1)
    {
        if(tmp) puts("");
        tmp=1,ans1=0;
        e.clear();

        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ans1+=w;
        }

        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            e.push_back(edge(u,v,w));
        }

        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            e.push_back(edge(u,v,w));
        }

        ans2=mst(n);
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}
