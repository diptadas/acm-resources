#include <stdio.h>
int main()
{
    int n,i,j,v,x,l,c,a,b;
    while(scanf("%d",&n) && n!=0)
    {
        i=0;v=0;x=0;l=0;c=0;
        for(j=1; j<=n; j++)
        {
            if(j==100) c++;
            else
            {
                a=j/10;
                b=j%10;

                if(a==9)
                {
                    x++;
                    c++;
                }
                else if(a==4)
                {
                    x++;
                    l++;
                }
                else if(a==5)l++;
                else if(a>5)
                {
                    l++;
                    x+=(a-5);
                }
                else x+=a;


                if(b==4)
                {
                    i++;
                    v++;
                }
                else if(b==9)
                {
                    i++;
                    x++;
                }
                else if(b==5) v++;
                else if(b>5)
                {
                    v++;
                    i+=(b-5);
                }
                else i+=b;
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,i,v,x,l,c);
    }
    return 0;
}
