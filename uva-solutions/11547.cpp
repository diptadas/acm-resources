#include <stdio.h>
int main()
{
    int t,i,n,b;
    float a;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        a=((((((n*567)/9)+7492)*235)/47)-498)/10;
        b=(int)a%10;
        if(b<0) b*=-1;
        printf("%d\n",b);
    }
    return 0;
}
