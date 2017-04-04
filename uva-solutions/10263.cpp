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
#define Inf 100000000
#define mset(a, s) memset(a, s, sizeof (a))


using namespace std;




//vector templete

struct p                                         //point;
{
    double x,y;
    p(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

p mv(p a,p b)                                 //make vector
{
    return p(b.x-a.x,b.y-a.y);
}

double dp(p a,p b)                            //dot product
{
    return a.x*b.x+a.y*b.y;
}

double cp(p a,p b)                           //cross product
{
    return a.x*b.y-a.y*b.x;
}

p vr(p v,double an)                          //vector rotation an radious angle
{
    return p(v.x*cos(an)-v.y*sin(an),v.x*sin(an)+v.y*cos(an));
}

p add(p a,p b)                              //two vector add
{
    return p(a.x+b.x,a.y+b.y);
}

double value(p a)                            //value of a vector
{
    return sqrt(dp(a,a));
}

p lv(p a,double l)                           //l th time of a vector
{
    double v=value(a);
    return p((a.x*l)/v,(a.y*l)/v);
}

p pointseg(p a,p b,p c)                      //min distance point of a,b segment from point c
{
    if(dp(mv(a,b),mv(a,c))<0) return a;
    if(dp(mv(b,a),mv(b,c))<0) return b;
    double l=(dp(mv(a,b),mv(a,c)))/value(mv(a,b));
    return add(a,lv(mv(a,b),l));
}

double dis(p a,p b)                          //distance of two point
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//end of vector templete



int main()
{
    p a,b,c,mp,ans;
    double d,mn;
    int n;

    while(cin>>a.x>>a.y)
    {
        mn=Inf;
        cin>>n;
        cin>>b.x>>b.y;

        for(int i=0; i<n; i++)
        {
            cin>>c.x>>c.y;
            mp=pointseg(b,c,a);
            d=dis(a,mp);
            if(d<mn)
            {
                mn=d;
                ans=mp;
            }
            b=c;
        }
        printf("%.4lf\n%.4lf\n",ans.x,ans.y);
    }
    return 0;
}
