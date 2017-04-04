#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int m,n,x,y,i,k;
    while(scanf("%d",&k) && k!=0)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&x,&y);
            if(x==m || y==n) printf("divisa\n");
            else if(x<m && y>n) printf("NO\n");
            else if(x>m && y>n) printf("NE\n");
            else if(x<m && y<n) printf("SO\n");
            else if(x>m && y<n) printf("SE\n");
        }
    }
    return 0;
}

