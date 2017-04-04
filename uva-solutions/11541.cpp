#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tc,i,j,k,l,p;
    char a[100],b[20],c;
    scanf("%d",&tc);
    getchar();
    for(i=0; i<tc; i++)
    {
        gets(a);
        printf("Case %d: ",i+1);
        l=strlen(a);

        for(j=0; j<l; j++)
        {
            if(a[j]>='A' && a[j]<='Z') c=a[j];

            for(p=0; a[j+1]>='0' && a[j+1]<='9' && (j+1)<l; p++)
            {
                b[p]=a[++j];
            }
            b[p]='\0';

            for(k=0; k<atoi(b); k++)
            {
                printf("%c",c);
            }
        }
        printf("\n");
    }
    return 0;
}
