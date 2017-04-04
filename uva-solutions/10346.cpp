#include <stdio.h>
int main()
{
    int n,k,x,y;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        x=n;
        while(x>=k)
        {
            y=x/k;
            n+=y;
            x=(x%k)+y;
        }
        printf("%d\n",n);
    }
    return 0;
}
