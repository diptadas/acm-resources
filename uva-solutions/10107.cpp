#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int a[10005],i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
        sort(a,a+i+1);
        if(i%2 == 0)
        {
            printf("%d\n",a[(i/2)]);
        }
        else printf("%d\n",(a[i/2]+a[(i/2)+1])/2);
        i++;
    }
    return 0;
}

