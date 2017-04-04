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

int dx[]= {2,2,1,1,-1,-1,-2,-2};
int dy[]= {-1,1,-2,2,-2,2,-1,1};

int main()
{
    int i,sr,sc,dr,dc;
    char str[5];
    while(gets(str))
    {
        sc=str[0]-'a';
        sr=str[1]-'1';
        dc=str[3]-'a';
        dr=str[4]-'1';

        if(sr==dr && sc==dc)
        {
            printf("To get from %c%c to %c%c takes 0 knight moves.\n",str[0],str[1],str[3],str[4]);
            continue;
        }

        int board[8][8];
        memset(board,0,sizeof(board));

        queue<int> q[2];
        q[0].push(sr);
        q[1].push(sc);
        board[sr][sc]=1;

        while(!q[0].empty())
        {
            int x=q[0].front();
            int y=q[1].front();

            for(i=0; i<8; i++)
            {
                int xi=x+dx[i];
                int yi=y+dy[i];

                if(xi>=0 && xi<8 && yi>=0 && yi<8 && board[xi][yi]==0)
                {
                    if(xi==dr && yi==dc)
                    {
                        printf("To get from %c%c to %c%c takes %d knight moves.\n",str[0],str[1],str[3],str[4],board[x][y]);
                        goto end;
                    }
                    q[0].push(xi);
                    q[1].push(yi);
                    board[xi][yi]=board[x][y]+1;
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
