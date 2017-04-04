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
} ;


int k=0,wall[25];
bool taken[25];
double area[25];
p ar[105],h[25][105],pvt,m;


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

void hull(int n)
{
    int t=0;
    h[k][t++]=ar[0];
    h[k][t++]=ar[1];
    h[k][t++]=ar[2];

    for(int i=3; i<n; i++)
    {
        while(cp(mv(h[k][t-2],h[k][t-1]),mv(h[k][t-2],ar[i]))<0) t--;
        h[k][t++]=ar[i];
    }

    area[k]=0;
    h[k][t]=h[k][0];

    wall[k]=t;

    for(int i=0; i<t; i++)
    {
        area[k]+=(h[k][i].x*h[k][i+1].y)-(h[k][i].y*h[k][i+1].x);
    }

    area[k]=0.5*abs(area[k]);
}

double area3(p a,p b,p c) //area of triangle from 3 point
{
    double x=dis(a,b),y=dis(b,c),z=dis(c,a);
    double s=(x+y+z)/2;
    return sqrt(s*(s-x)*(s-y)*(s-z));
}


int main()
{
    int site;

    while(cin>>site && site!=-1)
    {
        cin>>ar[0].x>>ar[0].y;
        pvt=ar[0];
        for(int i=1; i<site; i++)
        {
            cin>>ar[i].x>>ar[i].y;
            if(ar[i].y<pvt.y || (ar[i].y==pvt.y && ar[i].x<pvt.x)) pvt=ar[i];
        }
        sort(ar,ar+site,cmp);
        hull(site);
        k++;
    }

    double ans=0;

    while(cin>>m.x>>m.y)
    {
        for(int i=0; i<k; i++)
        {
            if(taken[i]) continue;

            double area2=0;

            for(int j=0; j<wall[i]; j++) area2+=area3(h[i][j],h[i][j+1],m);

            if(fabs(area2-area[i])<EPS)
            {
                ans+=area2;
                taken[i]=1;
            }
        }
    }

    printf("%.2lf\n",ans);

    return 0;
}

