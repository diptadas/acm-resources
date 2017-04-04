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
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int main()
{
    LL n;
    while(scanf("%lld",&n) && n!=0)
    {
        LL ans=1;
        for(LL i=2; i<=sqrt(n*1.0)&& n!=1; )
        {
            LL p=0;
            while(n%i==0)
            {
                p++;
                n=n/i;
            }
            if(p)
            {
                ans*=(i-1)*pow(i*1.0,p-1);
            }
            if(i==2) i++;
            else i+=2;
        }
        if(n>1) ans*=(n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
