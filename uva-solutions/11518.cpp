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

int main()
{
    int tc,n,m,l;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m>>l;
        int a[n+1],cnt=0;
        vector<int> node[n+1];

        memset(a,0,sizeof(a));

        for(int i=0; i<m; i++)
        {
            int p,q;
            cin>>p>>q;
            node[p].push_back(q);
        }

        for(int i=0; i<l; i++)
        {
            int x;
            cin>>x;
            queue<int> q;
            q.push(x);

            while(!q.empty())
            {
                int t=q.front();
                if(a[t]==0)
                {
                    for(int j=0; j<node[t].size(); j++)
                    {
                        q.push(node[t][j]);
                    }
                }
                a[t]=1;
                q.pop();
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(a[i]) cnt++;
        }

        cout<<cnt<<endl;
    }
    return 0;
}

