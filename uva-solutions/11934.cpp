#include <stdio.h>
int main()
{
    int a,b,c,d,l,i,count;
    long long int f;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l))
    {
        if(a==0 && b==0 && c==0 && d==0 && d==0) break;
        for(i=0,count=0; i<=l; i++)
        {
            f=(a*i*i)+(b*i)+c;
            if(f%d == 0) count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
