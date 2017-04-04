#include <stdio.h>
int main()
{
    int n,mx=11,mn=0;
    while(scanf("%d",&n)&&n!=0)
    {
       char ch[5];
       scanf("%s %s",ch,ch);
       if(ch[0]=='o')
       {
           if(n>=mx || n<=mn || mx<=mn) printf("Stan is dishonest\n");
           else printf("Stan may be honest\n");
           mx=11,mn=0;
       }
       else if(ch[0]=='h')
       {
           if(n<mx) mx=n;
       }
       else
       {
           if(n>mn) mn=n;
       }
    }
    return 0;
}
