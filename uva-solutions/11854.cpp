#include <stdio.h>
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}
int main()
{
    int a,b,c;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==0 && b==0 && c==0) break;
        if(a>b && a>c) swap(&a,&c);
        else if(b>c) swap(&b,&c);
        if(c*c == a*a + b*b) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
