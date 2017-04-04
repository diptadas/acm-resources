/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @Topcoder   : dipta670
 *    @link       : www.fb.com/dipta.das
 */

#include<bits/stdc++.h>
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
#define NN         1000009


int main()
{
    LL n,m,t,i,j,k;

    double p,q,r,s,a,b;

    while(scanf("%lf %lf %lf",&p,&q,&r)==3)
    {
        s=p+q;
        a=(p/s)*(q/(s-r-1));
        b=(q/s)*((q-1)/(s-r-1));
        printf("%.5lf\n",a+b);
    }

    return 0;
}

