#include <stdio.h>
#include <string.h>
char a[1000], b[1000], c[1000];

rev()
{
    int i,j,l=strlen(c)-1;
    char t;
    for(i=0,j=l;i<=l/2;i++,j--)
    {
        t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}

add()
{
    int cry = 0,x,y,i,t;
    x=strlen(a)-1;
    y=strlen(b)-1;
    for (i = 0; ; i++,x--,y--)
    {
        if(x<0 && y<0)
        {
            if(cry==1)
            {
                c[i]='1';
                c[i+1]='\0';
            }
            else(c[i]='\0');
            break;
        }
        else if(x<0) t=cry+(b[y]-'0');
        else if(y<0) t=cry+(a[x]-'0');
        else  t=cry+(a[x]-'0')+(b[y]-'0');
        c[i]=(t%10)+'0';
        cry=t/10;
    }
    rev();
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        strcpy(a,"0");
        strcpy(b,"1");
        while(n)
        {
            add();
            strcpy(a,b);
            strcpy(b,c);
            n--;
        }
        puts(a);
    }
    return 0;
}
