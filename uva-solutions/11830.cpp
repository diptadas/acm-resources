#include <stdio.h>
#include <string.h>
int main()
{
    char a[1001],ch;
    int i,j,n;
    while(1)
    {
        scanf("%c",&ch);
        getchar();
        gets(a);
        if(ch=='0' && a[0]=='0') break;
        n=strlen(a);
        for(i=0,j=0; i<n; i++)
        {
            if(a[i]!=ch)
            {
                if(a[i]!='0')
                {
                    printf("%c",a[i]);
                    j=1;
                }
                else if(j==1) printf("%c",a[i]);
            }
        }
        if(j==0) printf("0\n");
        else printf("\n");
    }
    return 0;
}
