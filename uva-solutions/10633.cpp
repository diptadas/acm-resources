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
    LL n,ans;
    while(scanf("%lld",&n) && n)
    {
        ans=n+(n/9);
        if(n%9==0) printf("%lld ",ans-1);
        printf("%lld\n",ans);
    }
    return 0;
}

