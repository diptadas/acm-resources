#include <stdio.h>
#include <string.h>

h2d(char a[])
{
    int i,t,d=0,y=1;
    for(i=strlen(a)-1;i>=0;i--)
    {
      if(a[i]>='0' && a[i]<='9') t=a[i]-'0';
      else t=a[i]-'A'+10;
      d+=y*t;
      y*=16;
    }
    return d;
}
d2b(int d,char a[])
{
    int x,i=0;
    for(i=0;i<13;i++)
    {
        a[i]='0';
    }
    a[i]='\0';
    while(d)
    {
        x=d%2;
        d=d/2;
        a[--i]=x+'0';
    }
}

int main()
{
    int tc,i,p,q;
    char a[14],b[14],x[14],y[14],ch;
    scanf("%d",&tc);
    getchar();
    for(i=0;i<tc;i++)
    {
        scanf("%s %c %s",a,&ch,b);
        p=h2d(a);
        q=h2d(b);
        d2b(p,x);
        d2b(q,y);
        printf("%s %c %s = ",x,ch,y);
        if(ch=='+') printf("%d\n",p+q);
        else printf("%d\n",p-q);
    }
    return 0;
}
