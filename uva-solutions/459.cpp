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
#define Clear(a) memset(a,0,sizeof(a))
using namespace std;

vector<int> v[30];
int visit[30];

void dfs(int n)
{
    if(visit[n]==0)
    {
        visit[n]=1;
        for(int i=0;i<v[n].size();i++) dfs(v[n][i]);
    }
}

int main()
{
    int tc,n;
    char s[3];
    scanf("%d\n\n",&tc);

    for(int t=1; t<=tc; t++)
    {
        Clear(visit);
        Clear(v);
        gets(s);
        n=s[0]-'A';
        while(gets(s))
        {
            if(s[0]=='\0') break;
            v[s[0]-'A'].push_back(s[1]-'A');
            v[s[1]-'A'].push_back(s[0]-'A');
        }
        int cnt=0;
        for(int i=0;i<=n;i++)
        {
            if(visit[i]==0)
            {
                cnt++;
                dfs(i);
            }
        }
        printf("%d\n",cnt);
        if(t!=tc) puts("");
    }
    return 0;
}

