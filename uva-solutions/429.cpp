#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int check(string s1,string s2)
{
    int n=s1.size() - s2.size();

    if(n==0)
    {
        for(int i=0,j=0; i<s1.size(); i++)
        {
            if(s1[i]!=s2[i])
            {
                if(j) return 0;
                else j=1;
            }
        }
        return 1;
    }
    else if(n==1 || n==-1)
    {
        for(int i=0; i<s1.size() && i<s2.size(); i++)
        {
            if(s1[i]!=s2[i]) return 0;
        }
        return 1;
    }
    else return 0;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        vector<int> node[201];
        string word[201];
        int wn=0;

        while(cin>>word[wn++] && word[wn-1]!="*");
        getchar();

        for(int i=0; i<wn; i++)
        {
            for(int j=0; j<wn; j++)
            {
                if(i==j) continue;
                if(check(word[i],word[j]))
                {
                    node[i].push_back(j);
                }
            }
        }

        while(getline(cin,s) && s!="")
        {
            string s1,s2;
            int pos=s.find(" ");
            s1=s.substr(0,pos);
            s2=s.substr(pos+1);

            int source,dest;
            for(int i=0; i<wn; i++)
            {
                if(s1==word[i]) source=i;
                if(s2==word[i]) dest=i;
            }

            queue<int> q;
            int level[201]= {0};

            q.push(source);
            level[source]=1;

            while(!q.empty())
            {
                int u=q.front();
                for(int i=0; i<node[u].size(); i++)
                {
                    int v=node[u][i];

                    if(dest==v)
                    {
                        cout<<s1<<" "<<s2<<" "<<level[u]<<endl;
                        goto end;
                    }

                    if(level[v]==0)
                    {
                        q.push(v);
                        level[v]=level[u]+1;
                    }
                }
                q.pop();
            }
end:
            continue;
        }
        if(t) cout<<endl;
    }
    return 0;
}

