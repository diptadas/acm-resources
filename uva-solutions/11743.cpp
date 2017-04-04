#include <stdio.h>

int main()
{
    int a[16],n,i,j,b,s;
    scanf("%d",&n);
    for(j=0; j<n; j++)
    {
        for(i=0; i<16;i++)
        {
            scanf("%1d",&a[i]);
        }
        for(i=0,s=0; i<16; i++)
        {
            if(i%2==0)
            {
                b=a[i]*2;
                if(b>9) s+=1+(b%10);
                else s+=b;
            }
            else s+=a[i];
        }
        if(s%10 == 0) printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
