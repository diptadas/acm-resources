#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long long int b,ans,i,s,bln,aln,f;
    char ch,a[1000],b1[11];
    while(scanf("%s",a)!= EOF)
    {
        while(1)
        {
            ch=getchar();
            if(ch=='/' || ch=='%') break;
        }
        scanf("%lld",&b);
        sprintf(b1, "%lld", b);
        aln=strlen(a);
        bln=strlen(b1);

        if(aln<bln)
        {
            if(ch=='/') printf("0\n");
            else printf("%s\n",a);
        }

        else if(aln==bln)
        {
            if(atol(a)<b)
            {
                if(ch=='/') printf("0\n");
                else printf("%s\n",a);
            }
            else
            {
                if(ch=='/') printf("%d\n",atol(a)/b);
                else printf("%d\n",atol(a)%b);
            }
        }

        else
        {
            for(i=0,s=0,f=0; i<aln ;)
            {
                while(1)
                {
                    s=(s*10)+(a[i]-'0');
                    i++;

                    if(s>=b) break;
                    if(i==aln) break;
                    if(ch=='/' && f==1)printf("0");
                }

                f=1;
                ans=s/b;
                if(ch=='/') printf("%lld",ans);
                s=s%b;
                while(s==0 && i<aln && a[i]=='0')
                {
                    printf("0");
                    i++;
                }
            }
            if(ch=='%') printf("%lld",s);
            printf("\n");
        }
    }
    return 0;
}
