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
};

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



int main()
{
    int n,tc;
    p a[105],b[105];
    bool taken[105];

    cin>>tc;

    while(tc--)
    {
        cin>>n;
        mset(taken,0);

        for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;

        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(inseg(a[i],b[i],a[j],b[j])) taken[i]=taken[j]=1;
            }
            if(!taken[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

