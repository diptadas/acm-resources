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
#define EPS 1e-7
#define Mod 100000007
#define mset(a, s) memset(a, s, sizeof (a))
#define sqr(a) a*a

using namespace std;

struct P
{
    double x,y;
    P(double a=0,double b=0)
    {
        x=a,y=b;
    }
};

P MV(P a,P b)
{
    return P(b.x-a.x,b.y-a.y);
}

double CP(P a,P b)
{
    return (a.x*b.y)-(a.y*b.x);
}

int main()
{
    int tc;
    double x1,y1,x2,y2,x3,y3,x4,y4;

    cin>>tc;

    cout<<"INTERSECTING LINES OUTPUT"<<endl;

    while(tc--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        P a=MV(P(x1,y1),P(x2,y2)),b=MV(P(x3,y3),P(x4,y4)),c=MV(P(x1,y1),P(x4,y4));

        if(CP(a,b)==0)
        {
            if(CP(a,c)==0) cout<<"LINE"<<endl;
            else cout<<"NONE"<<endl;
        }
        else
        {
            double tmp=(x1-x2)*(y3-y4)-(x3-x4)*(y1-y2);
            double ix=((x1*y2-y1*x2)*(x3-x4)-(x3*y4-y3*x4)*(x1-x2))/tmp;
            double iy=((x1*y2-y1*x2)*(y3-y4)-(x3*y4-y3*x4)*(y1-y2))/tmp;
            printf("POINT %.2lf %.2lf\n",ix,iy);
        }
    }

    cout<<"END OF OUTPUT"<<endl;

    return 0;
}
