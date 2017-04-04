#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int i,n,edge;
    while(scanf("%d",&n) && n!=0)
    {
        scanf("%d",&edge);
        queue<int>q;
        vector<int> node[n];
        int color[n];
        memset(color,0,sizeof(color));

        for(i=0; i<edge; i++)
        {
            int m,n;
            scanf("%d %d",&n,&m);
            node[n].push_back(m);
            node[m].push_back(n);
        }
        q.push(0);
        color[0]=1;

        while(!q.empty())
        {
            int u=q.front();
            for(i=0; i<node[u].size(); i++)
            {
                int v=node[u][i];
                if(color[v]==0)
                {
                    color[v]=3-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u])
                {
                    printf("NOT BICOLORABLE.\n");
                    goto end;
                }
            }
            q.pop();
        }
        printf("BICOLORABLE.\n");
end:
        continue;
    }
    return 0;
}

