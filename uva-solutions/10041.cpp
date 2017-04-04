#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t,tc,n,i,m,sum,a[1000];
    scanf("%d",&tc);
    for(t=0; t<tc; t++)
    {
       scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        m=a[i/2];
        for(i=0,sum=0; i<n; i++)
        {
            sum+=abs(m-a[i]);
        }
        printf("%d\n",sum);
    }
    return 0;
}
