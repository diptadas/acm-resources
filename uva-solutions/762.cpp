#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n,first=1;
    while(scanf("%d",&n)==1)
    {
        if(!first) cout<<endl;
        first=0;

        map< string,int > mp;
        vector<int> node[1000];
        vector<string> city;
        queue<int> q;
        int parent[1000]= {0};
        int level[1000]= {0};

        string s1,s2;
        int source,dest;

        for(int i=0,t=0; i<n; i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1]=t++;
                city.push_back(s1);
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=t++;
                city.push_back(s2);
            }
            node[mp[s1]].push_back(mp[s2]);
            node[mp[s2]].push_back(mp[s1]);
        }

        cin>>s1>>s2;
        if(mp.find(s1)==mp.end() || mp.find(s2)==mp.end())
        {
            cout<<"No route"<<endl;
            continue;
        }
        source=mp[s1];
        dest=mp[s2];

        q.push(source);
        level[source]=1;

        while(!q.empty())
        {
            int u=q.front();
            for(int i=0; i<node[u].size(); i++)
            {
                int v=node[u][i];
                if(!level[v])
                {
                    parent[v]=u;
                    level[v]=level[u]+1;
                    q.push(v);
                    if(v==dest)
                    {
                        goto end;
                    }
                }
            }
            q.pop();
        }

        cout<<"No route"<<endl;
        continue;
end:
        int x=level[dest]-1;
        string route[x];
        for(int i=0; source!=dest; i++)
        {
            route[i]=city[parent[dest]]+" "+city[dest];
            dest=parent[dest];
        }
        for(int i=x-1; i>=0; i--)
        {
            cout<<route[i]<<endl;
        }
    }
    return 0;
}
