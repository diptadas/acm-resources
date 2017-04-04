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

/*
Catalan number :

n = 0,1,2,3,4,5.....
C = 1,1,2,5,14,42....

C(n) = (2n)! / ((n+1)! * n!)

Recurrence relation :

C(n) = C(n-1) * (4n-2) / (n+1)
*/

int c[11];

void catalan()
{
    c[0]=1;
    for(int i=1; i<=10; i++) c[i]=(c[i-1]*(4*i-2))/(i+1);
}

int main()
{
    int n,t=0;
    catalan();
    while(cin>>n)
    {
        if(t) puts("");
        cout<<c[n]<<endl;
        t=1;
    }
    return 0;
}
