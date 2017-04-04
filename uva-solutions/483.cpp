#include <stdio.h>
#include <string.h>

int main()
{
    int s,i,l,e;
    char a[1000];
    while(gets(a))
    {
        l=strlen(a);
        for(s=0,i=0; i<l; i++)
        {
            if(a[i+1]==32)
            {
                e=i;
                for(e; e>=s; e--) printf("%c",a[e]);
                printf("%c",32);
                s=i+2;
            }
            else if(i+1==l)
            {
                e=i;
                for(e; e>=s; e--) printf("%c",a[e]);
                printf("\n");
            }
        }
    }
    return 0;
}
