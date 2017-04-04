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

void fix_str(string s[],int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='0') s[i][j]='W';
        }
    }
}

int main()
{
    int tc;
    cin>>tc;
    getchar();
    getchar();

    while(tc--)
    {
        string s[105];
        char tmp[105];
        int i=0,r,c,n,m,count;

        while(1)
        {
            gets(tmp);
            if(tmp[0]=='L' || tmp[0]=='W') s[i++]=tmp;
            else break;
        }
        n=i,m=s[0].size();

up:
        sscanf(tmp,"%d %d",&r,&c);
        count=0;

        if(s[r-1][c-1]=='W')
        {
            count++;
            queue<int> row,col;
            row.push(r-1);
            col.push(c-1);
            s[r-1][c-1]='0';

            while(!row.empty())
            {
                int x=row.front();
                int y=col.front();

                for(int k=0; k<8; k++)
                {
                    int tx=x+dx[k];
                    int ty=y+dy[k];
                    if(tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty]=='W')
                    {
                        row.push(tx);
                        col.push(ty);
                        s[tx][ty]='0';
                        count++;
                    }
                }
                row.pop();
                col.pop();
            }
        }
        cout<<count<<endl;

        if(gets(tmp) && tmp[0]!='\0')
        {
            fix_str(s,n,m);
            goto up;
        }
        if(tc)cout<<endl;
    }
    return 0;
}

