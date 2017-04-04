#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct dna
{
    string str;
    int sn;
} temp;

int sort1(string str,int l)
{
    int i,j,n=0;
    char ch;
    for(i=0; i<l; i++)
    {
        for(j=0; j<l-i-1; j++)
        {
            if(str[j]>str[j+1])
            {
                ch=str[j];
                str[j]=str[j+1];
                str[j+1]=ch;
                n++;
            }
        }
    }
    return n;
}


void sort2(struct dna strlist[],int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(strlist[j].sn>strlist[j+1].sn)
            {
                temp=strlist[j];
                strlist[j]=strlist[j+1];
                strlist[j+1]=temp;
            }
        }
    }
}

int main()
{
    int t,l,n,i,j;
    scanf("%d",&t);

    for(; t; t--)
    {
        scanf("%d %d",&l,&n);
        getchar();
        struct dna strlist[n];
        for(i=0;i<n; i++)
        {
            cin>>strlist[i].str;
            strlist[i].sn=sort1(strlist[i].str,l);
        }
        sort2(strlist,n);

        for(i=0;i<n; i++)
        {
          cout<<strlist[i].str<<endl;
        }
        if(t-1) printf("\n");
    }
    return 0;
}
