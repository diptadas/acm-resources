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

string s[500];
int a[500][500],r,c;
int dx[]= {-1,0,1,-1,1,-1,0,1};
int dy[]= {1,1,1,0,0,-1,-1,-1};

void bfs(int i,int j,int cnt)
{
    char ch=s[i][j];
    queue<int> row,col;

    row.push(i);
    col.push(j);

    s[i][j]='0';
    a[i][j]=cnt;

    while(!row.empty())
    {
        int x=row.front();
        int y=col.front();
        for(int i=0; i<8; i++)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];
            if(tx>=0 && tx<r && ty>=0 && ty<c && s[tx][ty]==ch)
            {
                row.push(tx);
                col.push(ty);
                s[tx][ty]='0';
                a[tx][ty]=cnt;
            }
        }
        row.pop();
        col.pop();
    }
}

void print()
{
    int cnt=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(s[i][j]!='0')
                bfs(i,j,++cnt);
        }
    }

    int col[c];

    for(int j=0; j<c; j++)
    {
        col[j]=0;
        for(int i=0; i<r; i++)
        {
            if(a[i][j]>col[j]) col[j]=a[i][j];
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if (j==0)
            {
                if (col[j]<10) printf("%d", a[i][j]);
                else if (col[j]<100) printf("%2d", a[i][j]);
                else if (col[j]<1000) printf("%3d", a[i][j]);
                else if (col[j]<10000) printf("%4d", a[i][j]);
                else if (col[j]<100000) printf("%5d", a[i][j]);
            }
            else
            {
                if (col[j]<10) printf("%2d", a[i][j]);
                else if (col[j]<100) printf("%3d", a[i][j]);
                else if (col[j]<1000) printf("%4d", a[i][j]);
                else if (col[j]<10000) printf("%5d", a[i][j]);
                else if (col[j]<100000) printf("%6d", a[i][j]);
            }
        }
        cout<<endl;
    }
    cout<<"%"<<endl;;
}

int main()
{
    char tmp[500];
    r=0;

    while(gets(tmp))
    {
        if(tmp[0]=='%')
        {
            c=s[0].size();
            print();
            r=0;
        }
        else
        {
            s[r]="";
            for(int i=0; i<strlen(tmp); i+=2) s[r]+=tmp[i];
            r++;
        }
    }

    c=s[0].size();
    print();

    return 0;
}

