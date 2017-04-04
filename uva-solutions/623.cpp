//Dipta Das CUET CSE-11

#include <stdio.h>
#include <string.h>
char a[1001][2600];

void rev(char a[])
{
    int i,j,l=strlen(a)-1;
    char t;
    for(i=0,j=l; i<=l/2; i++,j--)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}


void fect()
{
    int t,i,j,k,len,n,sum;
    sprintf(a[0],"%d",1);
    sprintf(a[1],"%d",1);

    for(t=2; t<=1000; t++)
    {
        len=strlen(a[t-1])-1;
        memset(a[t],48,sizeof(a[i]));

        for(n=t,i=0,sum=0; n!=0; n=n/10,i++)
        {
            for(j=len,k=i; j>=0; j--)
            {
                sum=(a[t][k]-'0')+((n%10)*(a[t-1][j]-'0'))+sum;
                a[t][k++]=sum%10+'0';
                sum=sum/10;
            }
            if(sum)
            {
                a[t][k++]+=sum;
                sum=0;
            }
        }
        a[t][k]='\0';
        rev(a[t]);
    }
}

int main()
{
    int i,j,n;
    fect();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d!\n",n);
        puts(a[n]);
    }
    return 0;
}

