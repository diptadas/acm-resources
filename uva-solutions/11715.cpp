#include <stdio.h>
#include <math.h>
void t1()
{
    double u,v,a,t,s;
    scanf("%lf %lf %lf",&u,&v,&t);
    a=(v-u)/t;
    s=(u*t)+(.5*a*t*t);
    printf("%.3lf %.3lf\n",s,a);
}

void t2()
{
    double u,v,a,t,s;
    scanf("%lf %lf %lf",&u,&v,&a);
    t=(v-u)/a;
    s=(u*t)+(.5*a*t*t);
    printf("%.3lf %.3lf\n",s,t);
}

void t3()
{
    double u,v,a,t,s;
    scanf("%lf %lf %lf",&u,&a,&s);
    v=sqrt((u*u)+(2*a*s));
    t=(v-u)/a;
    printf("%.3lf %.3lf\n",v,t);
}

void t4()
{
    double u,v,a,t,s;
    scanf("%lf %lf %lf",&v,&a,&s);
    u=sqrt((v*v)-(2*a*s));
    t=(v-u)/a;
    printf("%.3lf %.3lf\n",u,t);
}

int main()
{
    int t,i=1;
    while(1)
    {
        scanf("%d",&t);
        if(t==0) break;
        printf("Case %d: ",i++);
        if(t==1) t1();
        else if(t==2) t2();
        else if(t==3) t3();
        else if(t==4) t4();
    }
    return 0;
}
