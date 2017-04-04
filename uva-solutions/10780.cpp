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

int call(int n,int i) //factors of i(prime) in n!
{
    int ret=0;
    while(n)
    {
        n/=i;
        ret+=n;
    }
    return ret;
}

int main()
{
    int tc,m,n;
    scanf("%d",&tc);

    for(int t=1; t<=tc; t++)
    {
        scanf("%d %d",&m,&n);

        int ans=0x7fffffff;

        for(int i=2; i<=sqrt(m); i++)
        {
            int cnt=0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            if(cnt) ans=min(ans,call(n,i)/cnt);
        }
        if(m>1) ans=min(ans,call(n,m));

        printf("Case %d:\n",t);
        if(ans) printf("%d\n",ans);
        else printf("Impossible to divide\n");
    }
    return 0;
}
