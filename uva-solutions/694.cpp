#include <stdio.h>
int main()
{
    long long int a,l;
    int t,c;
    for(c=1;; c++)
    {
        scanf("%lld %lld",&a,&l);
        if(a<0 && l<0) break;
        printf("Case %d: A = %lld, limit = %lld, ",c,a,l);
        for(t=0; a<=l; t++)
        {
            if(a==1)
            {
                t++;
                break;
            }
            if(a%2==0) a=a/2;
            else a=(3*a)+1;
        }
        printf("number of terms = %d\n",t);
    }
    return 0;
}
