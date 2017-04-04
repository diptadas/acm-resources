#include <stdio.h>
#include <string.h>
int main()
{
    int i,t,ln;
    float n;
    char str[11];
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        gets(str);
        ln=strlen(str);
        if(ln==4) n=(str[0]-'0')*0.5;
        else if(ln==8) n=(str[0]-'0')*0.5 + (str[4]-'0')*0.05;
        else if(ln==5) n=5;
        else n=5+ (str[5]-'0')*0.05;
        printf("Case %d: %g\n",i,n);
    }
}
