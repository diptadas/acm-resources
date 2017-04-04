#include <stdio.h>
#include <string.h>
int main()
{
    char a[201];
    int b[26],n,t,tc,i,h;
    scanf("%d",&tc);
    getchar();
    for(t=0; t<tc; t++)
    {
        gets(a);

        for(i=0; i<26; i++)
        {
            b[i]=0;
        }

        h=0;

        for(i=0; i<strlen(a); i++)
        {
            a[i]=tolower(a[i]);
            if(a[i]>='a' && a[i]<='z')
            {
                n=a[i]-'a';
                b[n]++;
                if(b[n]>h) h=b[n];
            }
        }

        for(i=0; i<26; i++)
        {
            if(b[i]==h) printf("%c",(i+'a'));
        }
        printf("\n");
    }
    return 0;
}
