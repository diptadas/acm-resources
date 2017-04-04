#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n;
    char a[105];
    while(scanf("%d",&n))
    {
        if(n==0) break;
        getchar();
        gets(a);
        n=strlen(a)/n;
        for(i=0; i<strlen(a); i+=n)
        {
            for(j=i+n-1; j>=i; j--)
            {
                printf("%c",a[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
