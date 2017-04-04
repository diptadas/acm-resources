#include <stdio.h>
#include <string.h>

struct cryptanalysis
{
    int num,ch;
} count[100],temp;


int main()
{
    int nl,i,j,k,t;
    char a[100][100];
    scanf("%d",&nl);
    getchar();

    for(i=0; i<nl; i++)
    {
        gets(a[i]);
    }

    for(i=0; i<26; i++)
    {
        count[i].ch=i;
        count[i].num=0;
    }

    for(i=0; i<nl; i++)
    {
        for(j=0; j<strlen(a[i]); j++)
        {
            if(toupper(a[i][j])>=65 && toupper(a[i][j])<=90)
            {
                k=toupper(a[i][j])-65;
                count[k].num++;
            }
        }
    }

    for(i=0; i<26; i++)
    {
        for(j=0; j<25-i; j++)
        {
            if(count[j].num<count[j+1].num)
            {
                temp=count[j];
                count[j]=count[j+1];
                count[j+1]=temp;
            }
        }
    }

    for(i=0; i<26; i++)
    {
        if(count[i].num) printf("%c %d\n",count[i].ch+'A',count[i].num);
    }

    return 0;
}
