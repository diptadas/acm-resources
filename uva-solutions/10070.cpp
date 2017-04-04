#include <stdio.h>
#include <string.h>

int main()
{
    int i,nw=0,od,lp,m4,m15,m55,m100,m400;
    char a[10000];
    while(scanf("%s",a)!=EOF)
    {
        if(nw==1) printf("\n");
        lp=od=m4=m15=m55=m100=m400=0;
        nw=1;
        for(i=0; i<strlen(a); i++)
        {
            m4=((m4*10)+(a[i]-'0'))%4;
            m15=((m15*10)+(a[i]-'0'))%15;
            m55=((m55*10)+(a[i]-'0'))%55;
            m100=((m100*10)+(a[i]-'0'))%100;
            m400=((m400*10)+(a[i]-'0'))%400;
        }
        if((m4==0&&m100!=0)||m400==0)
        {
            printf("This is leap year.\n");
            lp=1;
            od=1;
        }
        if(m15==0)
        {
            printf("This is huluculu festival year.\n");
            od=1;
        }
        if(lp==1&&m55==0) printf("This is bulukulu festival year.\n");
        if(od==0) printf("This is an ordinary year.\n");
    }
    return 0;
}
