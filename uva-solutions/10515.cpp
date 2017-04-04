#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,l,t;
    char a[105],b[105];
    while(1)
    {
        scanf("%s",a);
        scanf("%s",b);

        if(a[0]=='0' && a[1]=='\0' && b[0]=='0' && b[1]=='\0') break;

        i=a[strlen(a)-1]-'0';

        l=strlen(b);
        if(l>=2)
        {
            j=(10*(b[l-2]-'0'))+(b[l-1]-'0');
            if(j==0) j=100;
        }
        else j=b[l-1]-'0';

        if(i==0) t=0;
        else if(i==1) t=1;
        else if(j==0) t=1;
        else if(i==5) t=5;
        else if(j==100)
        {
            if(i%2 == 0) t=6;
            else t=1;
        }
        else
        {
            for(t=1; j; j--)
            {
                t=(t*i)%10;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}
