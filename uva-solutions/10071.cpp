#include<stdio.h>
int main()
{
    long int v,s,t;
    while(scanf("%ld%ld",&v,&t)!=EOF)
    {
        s=v*2*t;
        printf("%ld\n",s);
    }
    return 0;
}
