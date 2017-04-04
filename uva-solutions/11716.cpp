#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int t,tc,x,n,i,j;
    char a[10005];
    scanf("%d",&tc);
    getchar();
    for(t=0; t<tc; t++)
    {
        gets(a);
        x=strlen(a);
        n=sqrt(x);
        if((n*n)!=x) printf("INVALID\n");
        else
        {
            for(i=0; i<n; i++)
            {
                for(j=i; j<=x-n+i; j+=n)
                {
                    printf("%c",a[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
