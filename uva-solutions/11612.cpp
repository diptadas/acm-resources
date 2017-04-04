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
    int n;
    double x,y;
    p(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
} ar[1005],pvt;

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
    if(c!=0) return c>0;
    return dis(pvt,a)<dis(pvt,b);
}


int main()
{
    int n;
    while(cin>>n && n)
    {
        ar[0].n=0;
        cin>>ar[0].x>>ar[0].y;
        pvt=ar[0];

        for(int i=1; i<n; i++)
        {
            ar[i].n=i;
            cin>>ar[i].x>>ar[i].y;
            if(ar[i].y<pvt.y || (ar[i].y==pvt.y && ar[i].x<pvt.x)) pvt=ar[i];
        }

        sort(ar,ar+n,cmp);

        if(cp(mv(ar[1],pvt),mv(ar[n-1],pvt))==0)
        {
            cout<<"no solution"<<endl;
            continue;
        }

        int tmp=n-1;
        while(cp(mv(ar[n-1],pvt),mv(ar[tmp-1],pvt))==0) tmp--;

        for(int i=n-1,j=tmp; i>j; i--,j++) swap(ar[i],ar[j]);

        for(int i=0; i<n; i++)
        {
            if(ar[i].n==0)
            {
                int st=i;
                while(1)
                {
                    cout<<ar[st].n<<" ";
                    st=(st+1)%n;
                    if(st==i) break;
                }
                break;
            }
        }
        cout<<"0"<<endl;
    }
    return 0;
}
