#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int table[2000001];

int main()
{
    int n,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(i=0; i<n; i++)
        {
            scanf("%d",&table[i]);;
        }
        sort(table,table+n);
        for(i=0; i<n; i++)
        {
            if(i== n-1) printf("%d",table[i]);
            else printf("%d ",table[i]);
        }
        printf("\n");
    }
    return 0;
}
