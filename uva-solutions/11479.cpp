#include <stdio.h>
int main()
{
    long long int t,i,a,b,c;
    scanf("%lld",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a+b<=c || b+c<=a || c+a<=b || a==0 || b==0 ||c==0) printf("Case %lld: Invalid\n",i+1);
        else if(a==b && b==c) printf("Case %lld: Equilateral\n",i+1);
        else if(a==b || b==c || c==a) printf("Case %lld: Isosceles\n",i+1);
        else printf("Case %lld: Scalene\n",i+1);
    }
    return 0;
}
