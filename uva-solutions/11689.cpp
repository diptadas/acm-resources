#include <stdio.h>
int main()
{
    int tc,e,f,c,n,i,j;
    scanf("%d",&tc);
    for(i=0; i<tc; i++)
    {
        scanf("%d %d %d",&e,&f,&c);
        n=e+f;
        for(j=0; n>=c;)
        {
            j+=n/c;
            n=(n/c)+(n%c);
        }
        printf("%d\n",j);
    }
    return 0;
}
