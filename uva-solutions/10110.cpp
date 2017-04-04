#include <stdio.h>
#include <math.h>

int main()
{
    long int n,r;
    while(scanf("%ld",&n) && n!=0)
    {
        r= sqrt(n);
        if ((r*r)== n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
