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
int dx[]= {1,-1,0,0},dy[]= {0,0,1,-1},row;
char s[50][100];
bool visit[50][100];

void dfs(int x,int y,char ch)
{
    if(x>=0 && x<row && y>=0 && y<strlen(s[x]) && s[x][y]!='X' && visit[x][y]==0)
    {
        visit[x][y]=1;
        s[x][y]=ch;
        for(int i=0; i<4; i++) dfs(x+dx[i],y+dy[i],ch);
    }
}

void color()
{
    memset(visit,0,sizeof(visit));
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<strlen(s[i]); j++)
        {
            if(s[i][j]!='X' && s[i][j]!=' ' && visit[i][j]==0)
                dfs(i,j,s[i][j]);
        }
    }
    for(int i=0; i<=row; i++) cout<<s[i]<<endl;
}

int main()
{
    row=0;
    while(gets(s[row]))
    {
        if(s[row][0]=='_')
        {
            color();
            row=0;
        }
        else row++;
    }
    return 0;
}

