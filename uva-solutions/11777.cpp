#include <stdio.h>
void swap(int *x,int *y)
{
    int temp=*y;
    *y=*x;
    *x=temp;
}
int main()
{
    int t,i,t1,t2,t3,a,c1,c2,c3,s,c,sum;
    scanf("%d",&t);
    for(i=0,sum=0; i<t; i++)
    {
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&t3,&a,&c1,&c2,&c3);
        if(c1<c3) swap(&c1,&c3);
        if(c2<c3) swap(&c2,&c3);
        c=(c1+c2)/2;
        sum =(t1+t2+t3+a+c);
        s=(int)(sum/10);
        if(s==9 || s==10)
            printf("Case %d: A\n",i+1);
        else if(s==8)
            printf("Case %d: B\n",i+1);
        else if(s==7)
            printf("Case %d: C\n",i+1);
        else if(s==6)
            printf("Case %d: D\n",i+1);
        else if(s<6)
            printf("Case %d: F\n",i+1);
    }
    return 0;
}
