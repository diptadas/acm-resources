#include <stdio.h>
int main()
{
    int t,i;
    float a,b;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%f %f",&a,&b);
        b=(b*5)/9;
        a=a+b;
        printf("Case %d: %.2f\n",i+1,a);
    }
    return 0;
}

