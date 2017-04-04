#include <stdio.h>
#include <math.h>
int main()
{
    int i=1,a;
    float b;
    while(1)
    {
        scanf("%d",&a);
        if(a<0) break;
        b=ceil (log(a)/log(2));
        printf("Case %d: %.0f\n",i++,b);
    }
    return 0;
}
