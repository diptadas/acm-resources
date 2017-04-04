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

/*
ax + b(x+1) = c
put a = -c and b = c
c = c
*/

int main()
{
    int tc;
    LL x,k;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&x,&k);
        if(x%k) printf("%lld %lld\n",-x,x);
        else printf("0 %lld\n",k);
    }
    return 0;
}
