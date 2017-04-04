#include <stdio.h>

unsigned long long fectorial(unsigned long long n)
{
    if(n<=1) return 1;
    else return(n*fectorial(n-1));
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
        {
            if(n%2 == 0) printf("Underflow!\n");
            else printf("Overflow!\n");
        }
        else
        {
            if(n<8) printf("Underflow!\n");
            else if(n>13) printf("Overflow!\n");
            else printf("%llu\n",fectorial(n));
        }
    }
    return 0;
}

