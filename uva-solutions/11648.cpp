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

int main()
{
    int tc;
    double a,b,c,d,h,hh,A,AA,dif,x,y,xx,yy,hi,lo,t1,t2;

    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        cin>>a>>b>>c>>d;

        dif=a-b;

        x=(sqr(c)+sqr(dif)-sqr(d))/(2*dif);
        y=dif-x;

        h=sqrt(sqr(c)-sqr(x));

        t1=atan(h/x),t2=atan(h/y);

        A=0.5*h*(a+b);
        A=A/2.0;

        lo=0,hi=h;

        while(fabs(hi-lo)>EPS)
        {
            hh=(lo+hi)/2.0;

            xx=hh/tan(t1),yy=hh/tan(t2);

            AA=0.5*hh*(2.0*a-xx-yy);

            if(AA>A) hi=hh;
            else lo=hh;
        }

        printf("Land #%d: %.6lf %.6lf\n",t,hh/abs(sin(t1)),hh/abs(sin(t2)));
    }
    return 0;
}
