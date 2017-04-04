#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int i,j,k,t,a,b,n,m,nc,tc=0;
    while(scanf("%d",&nc)&&nc!=0)
    {
        map< int,int > mp;
        vector<int> node[31];
        for(i=0,t=0; i<nc; i++)
        {
            cin>>n;
            cin>>m;
            if(mp.find(n)==mp.end()) mp[n]=t++;
            if(mp.find(m)==mp.end()) mp[m]=t++;
            node[mp[n]].push_back(m);
            node[mp[m]].push_back(n);
        }
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            int taken[30]= {0};
            int count=0;
            vector<int>V1,V2;
            V1.push_back(a);
            taken[mp[a]]=1;

            for(int level=1; level<=b; level++)
            {
                for(int i=0; i<V1.size(); i++)
                {
                    int u=V1[i];
                    for(int j=0; j<node[mp[u]].size(); j++)
                    {
                        int v=node[mp[u]][j];
                        if(!taken[mp[v]])
                        {
                            taken[mp[v]]=1;
                            count++;
                            V2.push_back(v);
                        }

                    }
                }
                if(V2.empty()) break;
                else
                {
                    V1.clear();
                    V1=V2;
                    V2.clear();
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,mp.size()-count-1,a,b);
        }
    }
    return 0;
}

/* Queue

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int a,b,n,m,nc,tc=0;
    while(scanf("%d",&nc)&&nc!=0)
    {
        map< int,int > mp;
        vector<int> node[31];
        queue<int> q;
        for(int i=0,t=0; i<nc; i++)
        {
            cin>>n;
            cin>>m;
            if(mp.find(n)==mp.end()) mp[n]=t++;
            if(mp.find(m)==mp.end()) mp[m]=t++;
            node[mp[n]].push_back(m);
            node[mp[m]].push_back(n);
        }
        while(cin>>a>>b)
        {
            if(a==0 && b==0) break;
            int level[30]= {0};
            int c=0;
            q.push(a);
            level[mp[a]]=1;

            while(!q.empty())
            {
                int u=q.front();
                for(int i=0; i<node[mp[u]].size() && level[mp[u]]<=b; i++)
                {
                    int v=node[mp[u]][i];
                    if(!level[mp[v]])
                    {
                        c++;
                        level[mp[v]]=level[mp[u]]+1;
                        q.push(v);
                    }
                }
                q.pop();
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,mp.size()-c-1,a,b);
        }
    }
    return 0;
}
*/

