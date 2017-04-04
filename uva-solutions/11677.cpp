#include <stdio.h>
int main()
{
    int a,b,c,d,p;
    while(1)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==0 && b==0 && c==0 && d==0) break;
        if(b>d)
        {
            d=d+60;
            c=c-1;
        }
        if(a>c) c=c+24;
        p=((c-a)*60) + (d-b);
        printf("%d\n",p);
    }
    return 0;
}
