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
#include <list>
#include <set>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define Set(a, s) memset(a, s, sizeof (a))

using namespace std;

int main()
{
    double x,y,c,c1,d,A,B,lo,hi;

    while(~scanf("%lf %lf %lf",&x,&y,&c))
    {
        lo=0;
        hi=min(x,y);
        c1=0;

        while(fabs(c-c1)>EPS)
        {
            d=(lo+hi)/2;
            A=acos(d/y);
            B=acos(d/x);
            c1=d*tan(A)*tan(B)/(tan(A)+tan(B));
            if(c1<c) hi=d-EPS;
            else lo=d+EPS;
        }

        printf("%.3lf\n",d);
    }
    return 0;
}


