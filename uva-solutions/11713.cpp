#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int t,n,i;
    scanf("%d\n",&t);
    for(n=1; n<=t; n++)
    {
        gets(a);
        gets(b);
        if(strlen(a)!=strlen(b)) printf("No\n");
        else
        {
            for(i=0; i<strlen(a); i++)
            {
                if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u'&&a[i]!=b[i])
                {
                    printf("No\n");
                    break;
                }
            }
            if(i==strlen(a)) printf("Yes\n");
        }
    }
    return 0;
}
