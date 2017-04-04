#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[5000001],b[500001];

int main()
{
    int n,i;
    while(scanf("%d",&n) && n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
       sort(a,a+n);
       sort(b,b+n);
       for(i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                printf("NO\n");
                break;
            }
        }
        if(i==n) printf("YES\n");
    }
    return 0;
}
