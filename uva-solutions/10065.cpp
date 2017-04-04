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

struct p //point;
{
    double x,y;
    p(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
} ar[105],pvt,h[105];

p mv(p a,p b) //make vector
{
    return p(b.x-a.x,b.y-a.y);
}

double dp(p a,p b) //dot product
{
    return a.x*b.x+a.y*b.y;
}

double cp(p a,p b) //cross product
{
    return a.x*b.y-a.y*b.x;
}

p vr(p v,double an) //vector rotation an radious angle
{
    return p(v.x*cos(an)-v.y*sin(an),v.x*sin(an)+v.y*cos(an));
}

p add(p a,p b) //two vector add
{
    return p(a.x+b.x,a.y+b.y);
}

double value(p a) //value of a vector
{
    return sqrt(dp(a,a));
}

p lv(p a,double l) //l th time of a vector
{
    double v=value(a);
    return p((a.x*l)/v,(a.y*l)/v);
}

p pointseg(p a,p b,p c) //min distance point of a,b segment from point c
{
    if(dp(mv(a,b),mv(a,c))<0) return a;
    if(dp(mv(b,a),mv(b,c))<0) return b;
    double l=(dp(mv(a,b),mv(a,c)))/value(mv(a,b));
    return add(a,lv(mv(a,b),l));
}

double dis(p a,p b) //distance of two point
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool onseg(p a,p b,p c) //if a,b,c colinear check if c lies on a,b segment
{
    return (c.x>=min(a.x,b.x) && c.x<=max(a.x,b.x) && c.y>=min(a.y,b.y) && c.y<=max(a.y,b.y));
}

bool inseg(p a,p b,p c,p d) //check if a,b and c,d segment intersect
{
    double d1,d2,d3,d4;
    d1=cp(mv(a,b),mv(a,c));
    d2=cp(mv(a,b),mv(a,d));
    d3=cp(mv(c,d),mv(c,a));
    d4=cp(mv(c,d),mv(c,b));

    if(d1*d2<0 && d3*d4<0) return true;

    if(d1==0 && onseg(a,b,c)) return true;
    if(d2==0 && onseg(a,b,d)) return true;
    if(d3==0 && onseg(c,d,a)) return true;
    if(d4==0 && onseg(c,d,b)) return true;

    return false;
}


//end of vector templete


bool cmp(p a,p b)
{
    double c=cp(mv(pvt,a),mv(pvt,b));

    if(c) return c>0;
    return dis(pvt,a)<dis(pvt,b);
}

double hull(int n)
{
    int t=0;
    h[t++]=ar[0];
    h[t++]=ar[1];
    h[t++]=ar[2];

    for(int i=3;i<n;i++)
    {
        while(cp(mv(h[t-2],h[t-1]),mv(h[t-2],ar[i]))<0) t--;
        h[t++]=ar[i];
    }

    double area=0;
    h[t]=h[0];

    for(int i=0;i<t;i++)
    {
        area+=(h[i].x*h[i+1].y)-(h[i].y*h[i+1].x);
    }

    area=0.5*abs(area);
    return area;
}

int main()
{
    int n,tc=1;
    while(cin>>n && n)
    {
        cin>>ar[0].x>>ar[0].y;
        pvt=ar[0];
        for(int i=1; i<n; i++)
        {
            cin>>ar[i].x>>ar[i].y;
            if(ar[i].y<pvt.y || (ar[i].y==pvt.y && ar[i].x<pvt.x)) pvt=ar[i];
        }

        ar[n]=ar[0];
        double area=0;

        for(int i=0;i<n;i++)
        {
            area+=(ar[i].x*ar[i+1].y)-(ar[i].y*ar[i+1].x);
        }

        area=0.5*abs(area);

        sort(ar,ar+n,cmp);

        double area2=hull(n);

        printf("Tile #%d\nWasted Space = %.2lf %\n\n",tc++,((area2-area)/area2)*100);

    }
    return 0;
}
