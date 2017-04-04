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
#define Inf 10000000000
#define mset(a, s) memset(a, s, sizeof (a))


using namespace std;



//vector templete

struct p //point;
{
    LL x,y;
    p(LL x=0,LL y=0)
    {
        this->x=x;
        this->y=y;
    }
} ar[100005],pvt;

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

double value(p a) //value of a vector
{
    return sqrt(dp(a,a));
}

double dis(p a,p b) //distance of two point
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


//end of vector templete



bool cmp(p a,p b)
{
    double c=cp(mv(pvt,a),mv(pvt,b));

    if(c) return c>0;
    return dis(pvt,a)<dis(pvt,b);
}


int main()
{
    LL tc,n,k,x,y,tmp,i,j;
    char ch;

    cin>>tc;
    while(tc--)
    {
        cin>>n;
        k=0;
        pvt=p(Inf,Inf);

        while(n--)
        {
            cin>>x>>y>>ch;
            if(ch=='Y')
            {
                ar[k++]=p(x,y);
                if(x<pvt.x || (x==pvt.x && y<pvt.y)) pvt=ar[k-1];
            }
        }
        sort(ar,ar+k,cmp);

        tmp=k-1;
        while(cp(mv(ar[k-1],pvt),mv(ar[tmp-1],pvt))==0) tmp--;

        for(i=k-1,j=tmp; i>j; i--,j++) swap(ar[i],ar[j]);

        printf("%lld\n",k);
        for(i=0; i<k; i++) printf("%lld %lld\n",ar[i].x,ar[i].y);
    }
    return 0;
}
