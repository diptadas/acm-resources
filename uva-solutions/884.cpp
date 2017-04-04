#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#define range 1000005
using namespace std;

bool prime[range+1];
long long fectors[1000001];
vector <long long> primelist;

void sieve()
{
    long long i,j;
    memset(prime,0,sizeof(prime));

    primelist.push_back(2);

    for(i=4; i<=range; i+=2)
        prime[i]=1;

    for(i=3; i<=range; i+=2)
    {
        if(prime[i]==0)
        {
            primelist.push_back(i);
            if(i*i<=range)
            {
                for(j=i*i; j<=range; j+=2*i)
                    prime[j]=1;
            }
        }
    }
}

long long fectorize(long long n)
{
    long long i=0,count=0,r=sqrt(n);

    while(primelist[i]<=r && n!=1)
    {
        while(n%primelist[i]==0)
        {
            count++;
            n=n/primelist[i];
        }
        r=sqrt(n);
        i++;
    }

    if(n>1) count++;
    return count;
}

void precalc()
{
    fectors[1]=0;
    for(long long i=2;i<=1000000;i++)
    {
        fectors[i]=fectors[i-1]+fectorize(i);
    }
}

int main()
{
    long long n,count;
    sieve();
    precalc();
    while(cin>>n)
    {
        cout<<fectors[n]<<endl;
    }
    return 0;
}
