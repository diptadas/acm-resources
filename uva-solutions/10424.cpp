#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int x,y,i,j,p,q;
    while(gets(a),gets(b))
    {
        x=strlen(a);
        y=strlen(b);
        for(i=0,p=0; i<x; i++)
        {
            if(a[i]>='A' && a[i]<='Z')
                p+=a[i]-64;
            if(a[i]>='a' && a[i]<='z')
                p+=a[i]-96;
        }
        for(i=0,q=0; i<y; i++)
        {
            if(b[i]>='A' && b[i]<='Z') q+=b[i]-64;
            if(b[i]>='a' && b[i]<='z') q+=b[i]-96;
        }
        while(p>9)
        {
            j=0;
            while(p)
            {
                j+=p%10;
                p=p/10;
            }
            p=j;
        }
        while(q>9)
        {
            j=0;
            while(q)
            {
                j+=q%10;
                q=q/10;
            }
            q=j;
        }
        if(p>=q) printf("%.2f %%\n",(float)q*100/p);
        else printf("%.2f %%\n",(float)p*100/q);
    }
    return 0;
}

