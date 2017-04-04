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

int par[1005],n,r,state;
double rail,road;

struct edge
{
    int u,v;
    double w;
    edge(int a,int b,double c)
    {
        u=a,v=b,w=c;
    }
    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

vector<edge> e;

int getParent(int i)
{
    return (par[i]==i)? i : getParent(par[i]);
}

void mst()
{
    state=1,rail=0,road=0;
    for(int i=0; i<n; i++) par[i]=i;

    sort(e.begin(),e.end());

    int cnt=0;

    for(int i=0; i<e.size() && cnt<n-1; i++)
    {
        int u=getParent(e[i].u),v=getParent(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            if(e[i].w>r)
            {
                state++;
                rail+=e[i].w;
            }
            else road+=e[i].w;
            cnt++;
        }
    }
}

int main()
{
    int tc,cod[1005][2];

    scanf("%d",&tc);
    for(int t=1; t<=tc; t++)
    {
        e.clear();
        scanf("%d %d",&n,&r);
        for(int i=0; i<n; i++) scanf("%d %d",&cod[i][0],&cod[i][1]);

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int x=cod[i][0]-cod[j][0],y=cod[i][1]-cod[j][1];
                double dis=sqrt(x*x+y*y);
                e.push_back(edge(i,j,dis));
            }
        }

        mst();

        printf("Case #%d: %d %.lf %.lf\n",t,state,road,rail);
    }
    return 0;
}

