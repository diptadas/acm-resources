#include <stdio.h>

int d2h(int d)
{
    int f=0,a=1;
    while(d)
    {
        f+=(d%10)*a;
        d/=10;
        a*=16;
    }
    return f;
}

int d2b(int d)
{
    int x,i=0;
    while(d)
    {
        x=d%2;
        d=d/2;
        if(x==1) i++;
    }
    return i;
}

int main()
{
    int a,b,tc,i;
    scanf("%d",&tc);
    for(i=0; i<tc; i++)
    {
        scanf("%d",&a);
        b=d2h(a);
        printf("%d %d\n",d2b(a),d2b(b));
    }
    return 0;
}
