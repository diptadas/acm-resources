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

bool visit[205];

struct edge
{
    int m,n,w;
    edge(int a,int b,int c)
    {
        m=a,n=b,w=c;
    }
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};

int main()
{
    int n,r,cs=0;
    while(cin>>n>>r)
    {
        if(n==0 && r==0) break;

        memset(visit,0,sizeof(visit));
        vector<int> v[n],v1[n];
        map<string,int> mp;
        priority_queue<edge> q;
        int parent[n][2];

        for(int i=0,t=0; i<r; i++)
        {
            string s1,s2;
            int w;
            cin>>s1>>s2>>w;
            if(mp.find(s1)==mp.end()) mp[s1]=t++;
            if(mp.find(s2)==mp.end()) mp[s2]=t++;
            v[mp[s1]].push_back(mp[s2]);
            v[mp[s2]].push_back(mp[s1]);
            v1[mp[s1]].push_back(w);
            v1[mp[s2]].push_back(w);
        }

        string s,d;
        cin>>s>>d;

        int ms=mp[s],md=mp[d];

        q.push(edge(-1,ms,0));

        while(!q.empty())
        {
            edge e=q.top();
            int t=e.n;

            visit[t]=1;
            parent[t][0]=e.m;
            parent[t][1]=e.w;

            if(t==md) break;
            q.pop();

            for(int i=0; i<v[t].size(); i++)
            {
                if(visit[v[t][i]]==0) q.push(edge(t,v[t][i],v1[t][i]));
            }
        }

        int tmp=md,mn=10001;
        while(1)
        {
            if(parent[tmp][1]<mn) mn=parent[tmp][1];
            if(parent[tmp][0]==ms) break;
            tmp=parent[tmp][0];
        }

        printf("Scenario #%d\n%d tons\n\n",++cs,mn);
    }
    return 0;
}
