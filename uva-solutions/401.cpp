#include <stdio.h>
#include <string.h>
int main()
{
    int ln,i,j,k,m,p;

    char a[100],
         b[21]= {'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'},
         c[21]= {'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'},
         d[13]= {'A','H','I','M','O','T','U','V','W','X','Y','1','8'};

    while(gets(a))
    {
        ln=strlen(a)-1;

        if(ln%2==0)
        {
            for(i=0; i<13; i++)
            {
                if(a[(ln/2)]==d[i]) break;
            }

            if(i==13) m=0;
            else m=1;
        }
        else m=1;

        for(i=0,j=ln,p=1; i<ln/2 && (m || p); i++,j--)
        {
            if(p)
            {
                if(a[i]!=a[j]) p=0;
            }

            if(m)
            {
                for(k=0; k<21; k++)
                {
                    if(a[i]==b[k]) break;
                }
                if(k==21) m=0;
                else if(a[j]!=c[k]) m=0;
            }
        }

        if(p==0 && m==0) printf("%s -- is not a palindrome.\n\n",a);
        else if(p==1 && m==0) printf("%s -- is a regular palindrome.\n\n",a);
        else if(p==0 && m==1) printf("%s -- is a mirrored string.\n\n",a);
        else printf("%s -- is a mirrored palindrome.\n\n",a);
    }
    return 0;
}
