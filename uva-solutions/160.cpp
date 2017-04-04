//Dipta Das @ CUET CSE 11

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
#define EPS        1e-7
#define MOD        1000000007
#define INF        1e9
#define NN         1000009

LL prime[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int main()
{

    LL i,j,k,n,cnt;

    while(read(n) && n)
    {

        printf("%3lld! =",n);

        for(i=0,j=0;prime[i]<=n;i++,j++)
        {
            if(j==15)
            {
                j=0;
                printf("\n      ");
            }
            cnt=0;
            k=n;
            while(k)
            {
                k/=prime[i];
                cnt+=k;
            }
            printf("%3lld",cnt);
        }
        puts("");
    }

    return 0;
}
