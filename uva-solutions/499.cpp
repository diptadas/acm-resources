#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    int b[52],n,i,h;

    while(gets(a))
    {
        for(i=0; i<52; i++)
        {
            b[i]=0;
        }

        h=0;

        for(i=0; i<strlen(a); i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                n=a[i]-'A';
                b[n]++;
                if(b[n]>h) h=b[n];
            }

            else if(a[i]>='a' && a[i]<='z')
            {
                n=a[i]-'a'+26;
                b[n]++;
                if(b[n]>h) h=b[n];
            }
        }

        for(i=0; i<52; i++)
        {
            if(b[i]==h)
            {
                if(i<26) printf("%c",(i+'A'));
                else printf("%c",(i+'a'-26));
            }
        }
        printf(" %d\n",h);
    }
    return 0;
}
