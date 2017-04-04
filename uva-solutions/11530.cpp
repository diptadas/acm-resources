#include <stdio.h>
int main()
{
    char a[110];
    int count,i,j,x,t;
    scanf("%d",&t);
    getchar();
    for(j=0; j<t; j++)
    {
        gets(a);
        for(i=0,count=0; a[i]; i++)
        {
            if(a[i]==' ') count++;
            else if(a[i]=='s' || a[i]=='z') count+=4;
            else
            {
                if(a[i]>'s') a[i]--;
                x=(a[i]-96)%3;
                if(x==0) x=3;
                count+=x;
            }
        }
        printf("Case #%d: %d\n",j+1,count);
    }
    return 0;
}
