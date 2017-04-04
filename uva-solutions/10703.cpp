#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int w,h,n,i,j,k,spot,x1,x2,y1,y2;
    while(cin>>w>>h>>n)
    {
        if(!w && !h && !n) break;
        spot=w*h;
        int a[w+1][h+1];
        memset (a, 0, sizeof(a));
        for(i=0; i<n; i++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            for(j=x1; j<=x2; j++)
            {
                for(k=y1; k<=y2; k++)
                {
                    if(a[j][k]==0)
                    {
                        a[j][k]=1;
                        spot--;
                    }
                }
            }

        }
        if(spot==0) printf("There is no empty spots.\n");
        else if(spot==1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n",spot);
    }
    return 0;
}

