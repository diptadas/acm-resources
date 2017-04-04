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

int main()
{
    int n,tc=1;
    while(cin>>n)
    {
        char a[n][n];
        int count=0;

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[i][j]=='1')
                {
                    count++;
                    queue<int> row;
                    queue<int> col;
                    row.push(i);
                    col.push(j);
                    while(!row.empty())
                    {
                        int x=row.front();
                        int y=col.front();

                        for(int k=0; k<8; k++)
                        {
                            int tx=x+dx[k];
                            int ty=y+dy[k];
                            if(tx>=0 && tx<n && ty>=0 && ty<n && a[tx][ty]=='1')
                            {
                                row.push(tx);
                                col.push(ty);
                                a[tx][ty]='0';
                            }
                        }
                        row.pop();
                        col.pop();
                    }
                }
            }
        }
        cout<<"Image number "<<tc++<<" contains "<<count<<" war eagles."<<endl;
    }
    return 0;
}
