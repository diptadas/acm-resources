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
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;

int main()
{
    int a,b,c;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==-1 && b==-1) break;
        c=abs(a-b);
        c=min(c,abs(c-100));
        printf("%d\n",c);
    }
    return 0;
}


