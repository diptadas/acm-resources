#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];
    int i,l;
    while(gets(a))
    {
        l=strlen(a);
        for(i=0; i<l; i++)
        {
            a[i]=a[i]-7;
        }
        puts(a);
    }
    return 0;
}
