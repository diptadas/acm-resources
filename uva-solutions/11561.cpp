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

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

int main()
{
    int w,h,sx,sy;
    while(cin>>w>>h)
    {
        char a[h][w+1];
        for(int i=0; i<h; i++) cin>>a[i];

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(a[i][j]=='P')
                {
                    sx=i;
                    sy=j;
                    goto next;
                }
            }
        }
next:

        int gold=0;

        queue<int> row,col;
        row.push(sx);
        col.push(sy);

        while(!row.empty())
        {
            int x=row.front();
            int y=col.front();
            int trap=0;

            for(int i=0; i<4; i++)
            {
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx>=0 && tx<h && ty>=0 && ty<w && a[tx][ty]=='T') trap=1;
            }

            if(trap==0)
            {
                for(int i=0; i<4; i++)
                {
                    int tx=x+dx[i];
                    int ty=y+dy[i];
                    if(tx>=0 && tx<h && ty>=0 && ty<w && a[tx][ty]!='#')
                    {
                        row.push(tx);
                        col.push(ty);
                        if(a[tx][ty]=='G') gold++;
                        a[tx][ty]='#';
                    }
                }
            }
            row.pop();
            col.pop();
        }
        cout<<gold<<endl;
    }
    return 0;
}
