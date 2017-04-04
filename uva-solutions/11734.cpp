#include <stdio.h>
#include <string.h>

int main()
{
    int tc,i,j,k,m,s;
    char a[100],b[100];
    scanf("%d",&tc);
    getchar();
    for(i=0; i<tc; i++)
    {
        gets(a);
        gets(b);

        if(strlen(a)<strlen(b)) printf("Case %d: Wrong Answer\n",i+1);

        else if(strlen(a)==strlen(b))
        {
            if(strcmp(a,b)==0) printf("Case %d: Yes\n",i+1);
            else printf("Case %d: Wrong Answer\n",i+1);
        }

        else
        {
            for(j=0,k=0,m=0,s=0; j<strlen(a); j++)
            {
                if(k==strlen(b))
                {
                    if(a[j]==' ') s=1;
                    else
                    {
                        m=0;
                        break;
                    }
                }
                else
                {
                    if(a[j]==b[k])
                    {
                        m=1;
                        k++;
                    }
                    else if(a[j]==' ')
                    {
                        m=0;
                        s=1;
                    }
                    else
                    {
                        m=0;
                        break;
                    }
                }
            }
            if(m==0 || k<strlen(b)) printf("Case %d: Wrong Answer\n",i+1);
            else if(m==1 && s==1) printf("Case %d: Output Format Error\n",i+1);
        }
    }
    return 0;
}
