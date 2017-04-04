//Dipta Das CUET CSE-11

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Mod 100000007
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int dx[]= {-1,0,1,-1,1,-1,0,1};
int dy[]= {1,1,1,0,0,-1,-1,-1};

int main()
{
    int n,m,x,y,cnt,tc=0;
    string s[101];
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0) break;
        if(tc) puts("");
        printf("Field #%d:\n",++tc);

        for(int i=0; i<n; i++) cin>>s[i];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='*') continue;
                cnt=0;
                for(int k=0; k<8; k++)
                {
                    x=i+dx[k];
                    y=j+dy[k];
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if(s[x][y]=='*') cnt++;
                }
                s[i][j]=cnt+'0';
            }
        }

        for(int i=0; i<n; i++) cout<<s[i]<<endl;
    }

    return 0;
}

