#include <stdio.h>
#include <string.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        char ch[6];
        scanf("%s",ch);
        if(strlen(ch)==5) printf("3\n");
        else
        {
            i=0;
            if(ch[0]=='o') i++;
            if(ch[1]=='n') i++;
            if(ch[2]=='e') i++;
            if(i>=2) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
