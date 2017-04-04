#include <stdio.h>
#include <string.h>

int main()
{
    char s[100001],sub[100001];
    int l,ls,tc,n,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",s);
        l=strlen(s);
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
        {
            scanf("%s",sub);
            ls=strlen(sub);
            if(ls>l) printf("n\n");
            else
            {
                for(j=0; j<ls; j++)
                {
                    if(sub[j]!=s[j])
                    {
                        printf("n\n");
                        break;
                    }
                }
                if(j==ls) printf("y\n");
            }
        }
    }
    return 0;
}
