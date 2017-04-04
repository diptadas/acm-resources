#include <stdio.h>
#include <string.h>

char f[5000][10000];

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
    int i,t,la,lb,cry = 0;
    la=strlen(a)-1;
    lb=strlen(b)-1;
    for (i = 0; ; i++,la--,lb--)
    {
        if(la<0 && lb<0)
        {
            if(cry==1)
            {
                c[i]='1';
                c[i+1]='\0';
            }
            else(c[i]='\0');
            break;
        }
        else if(la<0) t=cry+(b[lb]-'0');
        else if(lb<0) t=cry+(a[la]-'0');
        else  t=cry+(a[la]-'0')+(b[lb]-'0');
        c[i]=(t%10)+'0';
        cry=t/10;
    }
    rev(c);
}

int main()
{
    int i,n;
    strcpy(f[0],"0");
    strcpy(f[1],"1");
    for(i=2; i<=5000; i++)
    {
        add(f[i-2],f[i-1],f[i]);
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("The Fibonacci number for %d is %s\n",n,f[n]);
    }
    return 0;
}

