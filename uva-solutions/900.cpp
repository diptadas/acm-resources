#include <stdio.h>

int brick(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else return(brick(n-1)+brick(n-2));
}

int main()
{
    int s,n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        s=brick(n);
        printf("%d\n",s);
    }
    return 0;
}
