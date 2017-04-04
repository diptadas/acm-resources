#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,x,a,b,count;
    for(i=0; i<201; i++)
    {
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;
        for(count=0,j=a; j<=b; j++)
        {
            x=(int)sqrt(j);
            if(x*x==j) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
