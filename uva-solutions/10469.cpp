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
            c[i]='\0';
            break;
        }
        else if(x<0) t=b[y]-'0';
        else if(y<0) t=a[x]-'0';
        else  t=(a[x]-'0')+(b[y]-'0');
        if(t==2) c[i]='0';
        else c[i]=t+'0';
    }
    rev(c);
}

d2b(int d,char a[])
{
    int x,i=0;
    while(d)
    {
        x=d%2;
        d=d/2;
        a[i++]=x+'0';
    }
    a[i]='\0';
    rev(a);
}

b2d(char c[])
{
    int i=strlen(c)-1,d=0,x,y=1;
    for(; i>=0; i--)
    {
        x=(c[i]-'0')*y;
        d+=x;
        y*=2;
    }
    return d;
}

int main()
{
    char a[50],b[50],c[50];
    int x,y,z;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        d2b(x,a);
        d2b(y,b);
        add(a,b,c);
        z=b2d(c);
        printf("%d\n",z);
    }
    return 0;
}
