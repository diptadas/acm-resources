#include <stdio.h>
int main()
{
    int t,a,b,i;
    char c;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%c%d",&a,&c,&b);
        if(b!=0)
        {
            b=60-b;
            a=11-a;
        }
        else
        {
            a=12-a;
        }
        if(a<=0) a=12+a;
        printf("%0.2d:%0.2d\n",a,b);
    }
    return 0;
}
