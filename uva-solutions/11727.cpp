#include <stdio.h>
int main()
{
    int t,a,b,c,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if((a>b && a<c) || (a>c && a<b)) b=a;
        else if((c>a && c<b) || (c>b && c<a)) b=c;
        printf("Case %d: %d\n",i+1,b);
    }
    return 0;
}
