/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @link       : www.fb.com/dipta.das
 */

#include <bits/stdc++.h>
using namespace std;

#define LL         long long
#define pll        pair<LL,LL>
#define mp         make_pair
#define fr         first
#define sc         second
#define pb         push_back

#define read(n)    scanf("%lld",&n)
#define mset(a,s)  memset(a,s,sizeof(a))
#define all(a)     a.begin(),a.end()

#define PI         acos(-1.0)
#define EPS        1e-9
#define MOD        1000000007
#define INF        1e9
#define NN         10001

vector<LL> v;
char ans[NN];
LL last[NN];

void call(LL n, LL sum, LL pre)
{
    if(sum>NN || last[sum]) return;
    last[sum]=n;

    for(LL i=n+pre+1,j=0; i>=n+1; i--,j++) call(i, sum+i, j+i-1);
}

int main()
{
    freopen("perfect.in", "r", stdin);
    freopen("perfect-alter.out", "w", stdout);

    LL t=1,tc,n,i,j;

    call(1,1,0); // pre-calculation

    read(tc);

    while(tc--)
    {
        v.clear();
        mset(ans, 0);

        read(n);

        if(!last[n])
        {
            printf("Case %lld: LOL\n", t++);
            continue;
        }

        printf("Case %lld: ", t++);

        i=n;
        while(1)
        {
            v.pb(last[i]);
            i-=last[i];
            if(!i) break;
        }
        reverse(all(v));

        for (i=0; i<v.size(); i++)
        {
            ans[v[i]-1]=i+'A';
            v[i]--;
        }

        for(i=1,j=0;i<=n;i++)
        {
            while(v[j]==0) j++;
            if(ans[i-1]==0)
            {
                ans[i-1]=j+'A';
                v[j]--;
            }
        }
        ans[n]='\0';
        puts(ans);
    }

    return 0;
}
