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
#define Set(a, s) memset(a, s, sizeof (a))

using namespace std;

vector<int> primelist;
bool prime[32000];
int sz;

void sieve()
{
    prime[1]=1;
    for(int i=4; i<32000; i+=2) prime[i]=1;

    for(int i=3; i*i<32000; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<32000; j+=(2*i)) prime[j]=1;
        }
    }

    for(int i=2; i<32000; i++)
    {
        if(prime[i]==0) primelist.push_back(i);
    }
    sz=primelist.size();
}

int sum(int n)
{
    int s=0;
    while(n)
    {
        s+=n%10;
        n=n/10;
    }
    return s;
}

bool match(int n)
{
    int s=0,s1;
    s1=sum(n);
    for(int i=0; primelist[i]*primelist[i]<=n && i<sz; i++)
    {
        if(n==1) break;
        while(n%primelist[i]==0)
        {
            s+=sum(primelist[i]);
            n=n/primelist[i];
        }
    }
    if(n>1) s+=sum(n);
    return s1==s;
}

bool NotPrime(int n)
{
    if(n<32000) return prime[n];

    for(int i=0; primelist[i]*primelist[i]<=n && i<sz; i++)
    {
        if(n%primelist[i]==0) return 1;
    }
    return 0;
}

int main()
{
    sieve();
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        while(1)
        {
            n++;
            if(NotPrime(n) && match(n)) break;
        }
        printf("%d\n",n);
    }
    return 0;
}


