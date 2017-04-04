#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i,j,t,sum=0;
    string s;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        cin>>s;
        if(s=="donate")
        {
            scanf("%d",&j);
            sum+=j;
        }
        else printf("%d\n",sum);
    }
    return 0;
}
