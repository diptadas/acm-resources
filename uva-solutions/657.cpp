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

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
char a[51][51];
int w,h;

void bfs(int i,int j)
{
    queue<int> row;
    queue<int> col;

    row.push(i);
    col.push(j);
    a[i][j]='*';

    while(!row.empty())
    {
        int x=row.front();
        int y=col.front();

        for(int k=0; k<4; k++)
        {
            int tx=x+dx[k];
            int ty=y+dy[k];
            if(tx>=0 && tx<h && ty>=0 && ty<w && a[tx][ty]=='X')
            {
                row.push(tx);
                col.push(ty);
                a[tx][ty]='*';
            }
        }
        row.pop();
        col.pop();
    }
}

int main()
{
    int tc=1;
    while(cin>>w>>h &&w &&h)
    {
        vector<int> dot;

        for(int i=0; i<h; i++)
            cin>>a[i];

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(a[i][j]!='.')
                {
                    int count=0;
                    if(a[i][j]=='X')
                    {
                        count++;
                        bfs(i,j);
                    }

                    queue<int> row;
                    queue<int> col;

                    row.push(i);
                    col.push(j);
                    a[i][j]='.';

                    while(!row.empty())
                    {
                        int x=row.front();
                        int y=col.front();

                        for(int k=0; k<4; k++)
                        {
                            int tx=x+dx[k];
                            int ty=y+dy[k];
                            if(tx>=0 && tx<h && ty>=0 && ty<w && (a[tx][ty]=='*' || a[tx][ty]=='X'))
                            {
                                if(a[tx][ty]=='X')
                                {
                                    count++;
                                    bfs(tx,ty);
                                }
                                row.push(tx);
                                col.push(ty);
                                a[tx][ty]='.';
                            }
                        }
                        row.pop();
                        col.pop();
                    }
                    dot.push_back(count);
                }
            }
        }

        cout<<"Throw "<<tc++<<endl;
        sort(dot.begin(),dot.end());
        for(int i=0; i<dot.size(); i++)
        {
            if(i) cout<<" ";
            cout<<dot[i];
        }
        cout<<endl<<endl;
    }
    return 0;
}

/*
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

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
char a[51][51];
int w,h,cnt;

void dfs1(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w && a[x][y]=='X')
    {
        a[x][y]='*';
        for(int i=0; i<4; i++) dfs1(x+dx[i],y+dy[i]);
    }
}

void dfs(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w && a[x][y]!='.')
    {
        if(a[x][y]=='X')
        {
            cnt++;
            dfs1(x,y);
        }
        a[x][y]='.';
        for(int i=0; i<4; i++) dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    int tc=0;
    while(cin>>w>>h &&w &&h)
    {
        vector<int> dot;

        for(int i=0; i<h; i++) cin>>a[i];

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(a[i][j]!='.')
                {
                    cnt=0;
                    dfs(i,j);
                    dot.push_back(cnt);
                }
            }
        }

        cout<<"Throw "<<++tc<<endl;
        sort(dot.begin(),dot.end());
        for(int i=0; i<dot.size(); i++)
        {
            if(i) cout<<" ";
            cout<<dot[i];
        }
        cout<<endl<<endl;
    }
    return 0;
}
*/
