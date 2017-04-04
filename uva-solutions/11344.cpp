
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

char s[10000];

int mod(int m)
{
    int ret=0;
    for(int i=0; s[i]; i++)
    {
        ret=ret*10+(s[i]-'0');
        ret=ret%m;
    }
    return ret;
}

int main()
{
    int tc,n,m,flag;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s %d",s,&n);
        flag=0;
        while(n--)
        {
            scanf("%d",&m);
            if(!flag) flag=mod(m);
        }
        if(flag) printf("%s - Simple.\n",s);
        else printf("%s - Wonderful.\n",s);
    }
    return 0;
}
