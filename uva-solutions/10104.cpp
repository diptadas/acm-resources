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

typedef pair<int,int> pr;
#define x first
#define y second

int gcd;

pr ex_eucid(int a, int b)
{
    if(b == 0)
    {
        gcd=a;
        return pr(1,0);
    }
    else
    {
        pr p=ex_eucid(b,a%b);
        return pr(p.y, p.x - p.y * (a/b));
    }
}

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        pr p=ex_eucid(a,b);
        printf("%d %d %d\n",p.x,p.y,gcd);
    }
    return 0;
}
