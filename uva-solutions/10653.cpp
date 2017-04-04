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

int grid[1005][1005];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int main()
{
    int i,j,a,b,c,d,row,col,sr,sc,dr,dc;

    while(scanf("%d %d",&row,&col))
    {
        if(row==0 && col==0) break;

        memset(grid,0,sizeof(grid));

        scanf("%d",&a);

        for(i=0; i<a; i++)
        {
            scanf("%d %d",&b,&c);
            for(j=0; j<c; j++)
            {
                scanf("%d",&d);
                grid[b][d]=1;
            }
        }

        scanf("%d %d %d %d",&sr,&sc,&dr,&dc);

        if(sr==dr && sc==dc)
        {
            printf("0\n");
            continue;
        }

        queue<int> q[2];
        q[0].push(sr);
        q[1].push(sc);
        grid[sr][sc]=1;

        while(!q[0].empty())
        {
            int x=q[0].front();
            int y=q[1].front();

            for(i=0; i<4; i++)
            {
                int xi=x+dx[i];
                int yi=y+dy[i];

                if(xi>=0 && xi<row && yi>=0 && yi<col && grid[xi][yi]==0)
                {
                    if(xi==dr && yi==dc)
                    {
                        printf("%d\n",grid[x][y]);
                        goto end;
                    }
                    q[0].push(xi);
                    q[1].push(yi);
                    grid[xi][yi]=grid[x][y]+1;
                }
            }

            q[0].pop();
            q[1].pop();
        }
end:
        continue;
    }
    return 0;
}
