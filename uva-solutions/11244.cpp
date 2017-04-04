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

int dx[]= {-1,0,1,-1,1,-1,0,1};
int dy[]= {1,1,1,0,0,-1,-1,-1};
int r,c,cnt;
char a[105][105];

void dfs(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c && a[x][y]=='*')
    {
        cnt++;
        a[x][y]='.';
        for(int i=0;i<8;i++) dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    while(cin>>r>>c)
    {
        if(r==0 && c==0) break;
        int star=0;
        for(int i=0;i<r;i++) cin>>a[i];

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]=='*')
                {
                    cnt=0;
                    dfs(i,j);
                    if(cnt==1) star++;
                }
            }
        }
        cout<<star<<endl;
    }
    return 0;
}
