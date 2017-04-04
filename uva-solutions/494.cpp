#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000];
    int l,i,w,count;
    while(gets(a))
    {
        l=strlen(a);
        for(i=0,w=0,count=0; i<=l; i++)
        {
            if(w)
            {
                if((a[i]<'a' || a[i]>'z') && (a[i]<'A' || a[i]>'Z') || a[i]=='\0')
                {
                    count++;
                    w=0;
                }
            }
            else
            {
                if((a[i]>='a'&&a[i]<='z') || (a[i]>='A'&&a[i]<='Z')) w=1;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
