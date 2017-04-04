#include <stdio.h>
#include <string.h>
void rev(char a[])
{
    int i,j,l=strlen(a)-1;
    char t;
    for(i=0,j=l; i<=l/2; i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}

void add(char a[],char b[],char c[])
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
    rev(c);
}

int main()
{
    char a[110],b[110],c[110];
    b[0]='\0';
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='0') break;
        add(a,b,c);
        strcpy(b,c);
    }
    puts(c);
    return 0;
}
