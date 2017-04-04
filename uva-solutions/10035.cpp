#include <stdio.h>
int main()
{
    long long int a,b;
    int s,count;
    while(1)
    {
        scanf("%lld %lld",&a,&b);
        if(a==0 && b==0) break;

        s=0;
        count=0;

        do
        {
            s=s+(a%10)+(b%10);
            if(s>9)
            {
                count++;
                s=1;
            }
            else s=0;
            a=a/10;
            b=b/10;
        }
        while(a!=0 || b!=0);

        if(count==0) printf("No carry operation.\n");
        else if(count==1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",count);
    }
    return 0;
}
