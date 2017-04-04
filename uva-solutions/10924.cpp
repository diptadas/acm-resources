#include <stdio.h>
#include <string.h>
#include <math.h>

int prime(int n)
{
    int i;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    char a[21];
    int i,s;
    while(gets(a))
    {
        for(i=0,s=0; i<strlen(a); i++)
        {
            if(a[i]>96) a[i]=a[i]-96;
            else a[i]=a[i]-38;
            s+=a[i];
        }
        if(prime(s)) printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
