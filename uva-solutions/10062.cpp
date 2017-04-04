#include <stdio.h>
#include <string.h>

char a[1001];
struct s
{
    char x;
    int y;
} z[105],temp1;

void sort(int n)
{
    int i,j,temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void sort1(int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(z[j].y>z[j+1].y)
            {
                temp1=z[j];
                z[j]=z[j+1];
                z[j+1]=temp1;
            }
        }
    }
}

int main()
{
    int i,j,n,nl=0,count;
    char t;

    while( gets(a))
    {

        if(nl!=0) printf("\n");
        nl=1;
        n=strlen(a);
        sort(n);
        if(n!=0)
        {
            for(i=1,j=0, t=a[0],count=1; i<n; i++)
            {
                if(a[i]==t) count++;
                else
                {
                    z[j].x=t;
                    z[j].y=count;
                    j++;
                    t=a[i];
                    count=1;
                }
            }
            z[j].x=t;
            z[j].y=count;
            j++;
            sort1(j);
            for(i=0; i<j; i++)
            {
                printf("%d %d\n",z[i].x,z[i].y);
            }
        }
    }
    return 0;
}
