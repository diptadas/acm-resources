#include<stdio.h>

int main()
{
    int i,j,count,num,bin[100];

    while(scanf("%d",&num)==1)
    {
        if (num==0) break;
        count=0;
        i=0;
        while(num)
        {
            bin[i]=num%2;
            if(bin[i]!=0) count++;
            num=num/2;
            i++;
        }
        printf("The parity of ");
        for(j=i-1; j>=0; j--)
            printf("%d",bin[j]);
        printf(" is %d (mod 2).\n",count);
    }
    return 0;
}
