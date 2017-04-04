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

int lead(int n,int k)
{
    /*
    c = a^b
    log(c) = b*log(a) = Characteristic + Mantissa
    c = 10^(Characteristic + Mantissa) = 10^Characteristic + 10^Mantissa
    */
    double tmp=k*log10(n);
    tmp-=floor(tmp);
    tmp=pow(10.0,tmp);
    while(tmp>999) tmp/=10;
    while(tmp<100) tmp*=10;
    return (int)tmp;
}

int trail(int n,int k)
{
    if(k==1) return n%1000;
    if(k%2) return ((n%1000)*trail(n,k-1))%1000;
    int ret=trail(n,k/2);
    return (ret*ret)%1000;
}

int main()
{
    int tc,n,k;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        int ans1=lead(n,k),ans2=trail(n,k);
        printf("%d...%03d\n",ans1,ans2);
    }
    return 0;
}

