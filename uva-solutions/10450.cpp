#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,tc;
    long long int a,b,c;
    scanf("%d",&tc);
    for(i=0; i<tc; i++)
    {
        scanf("%d",&n);
        a=0;
        b=1;
        while(n>=0)
        {
            c=a+b;
            a=b;
            b=c;
            n--;
        }
        printf("Scenario #%d:\n%lld\n\n",i+1,b);
    }
    return 0;
}
