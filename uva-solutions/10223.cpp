/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @Topcoder   : dipta670
 *    @link       : www.fb.com/dipta.das
 */

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
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
#define NN         40000

LL cat[]={1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786,208012, 742900,
           2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420
          };

int main()
{
    LL n,m,i,j,k;

    while(read(n)==1)
    {
        for(i=0; ;i++) if(cat[i]>=n) break;
        printf("%lld\n",i+1);
    }

    return 0;
}

