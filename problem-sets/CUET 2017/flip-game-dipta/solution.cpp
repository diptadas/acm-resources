// Author: Dipta Das
// Complexity: O(T*M*N) (100*100*10: 10^5)

#include <bits/stdc++.h>

// consider 1 as HEAD and 0 as TAIL
bool board[11][11];

int main()
{
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    
    int t=1,tc,i,j,k,n,m,r,c,x,y;

    scanf("%d", &tc);

    while(tc--)
    {
        memset(board,0,sizeof(board)); // initially all tails

        scanf("%d %d", &n, &m);

        for(i=0; i<m; i++)
        {
            scanf("%d", &k);
            r=(k-1)/n;
            c=(k-1)%n;

            if(board[r][c]) // flip the row
                for(j=0; j<n; j++) board[r][j]=!board[r][j];
            else // flip the column
                for(j=0; j<n; j++) board[j][c]=!board[j][c];
        }

        for(x=0, y=0, i=0; i<n; i++)
            for(j=0; j<n; j++) if(board[i][j]) x++; else y++; 

        if(x>y) printf("Case %d: Alice\n", t++);
        else if(y>x) printf("Case %d: Bob\n", t++);
        else printf("Case %d: Draw\n", t++);
    }

    return 0;
}
