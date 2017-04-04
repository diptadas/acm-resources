#include <stdio.h>
int main()
{
    int t,i,a,b;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d %d",&a,&b);
        if(b>a) printf("impossible\n");
        else if((a+b)%2!=0 ||(a-b)%2!=0) printf("impossible\n");
        else printf("%d %d\n",(a+b)/2,(a-b)/2);
    }
    return 0;
}
