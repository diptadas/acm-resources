#include <stdio.h>
#include <string.h>

b2d(char c[])
{
    int i=strlen(c)-1,d=0,x,y=2;
    for(; i>=0; i--)
    {
        x=(c[i]-'0')*(y-1);
        d+=x;
        y*=2;
    }
    return d;
}

int main()
{
    char a[1000];
    int d;
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='0') break;
        d=b2d(a);
        printf("%d\n",d);
    }
    return 0;
}

