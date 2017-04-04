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
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,t,m,time;
        queue<int> l,l1,r,r1;
        cin>>n>>t>>m;
        int ans[m];
        for(int i=0; i<m; i++)
        {
            int x;
            char ch[7];
            cin>>x>>ch;
            if(ch[0]=='l') l.push(x),l1.push(i);
            else r.push(x),r1.push(i);
        }
        int pos=0;
        time=0;
        while(!l.empty() || !r.empty())
        {
            if(pos==0)
            {
                int i;
                for(i=0; i<n && !l.empty(); i++)
                {
                    if(l.front()<=time)
                    {
                        ans[l1.front()]=time+t;
                        l.pop();
                        l1.pop();
                    }
                    else break;
                }
                if(i==0)
                {
                    if(r.empty() || (!l.empty() && r.front()>l.front())) time=l.front();
                    else if(r.front()<=time) pos=1,time+=t;
                    else pos=1,time=r.front()+t;
                }
                else pos=1,time+=t;
            }
            else
            {
                int i;
                for(i=0; i<n && !r.empty(); i++)
                {
                    if(r.front()<=time)
                    {
                        ans[r1.front()]=time+t;
                        r.pop();
                        r1.pop();
                    }
                    else break;
                }
                if(i==0)
                {
                    if(l.empty() || (!r.empty() && r.front()<l.front())) time=r.front();
                    else if(l.front()<=time) pos=0,time+=t;
                    else pos=0,time=l.front()+t;
                }
                else pos=0,time+=t;
            }
        }
        for(int i=0; i<m; i++) cout<<ans[i]<<endl;
        if(tc) cout<<endl;
    }
    return 0;
}
