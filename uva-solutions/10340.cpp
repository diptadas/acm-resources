#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string a,b;
    int la,lb,i,j,f;
    while(cin>>a>>b)
    {
        la=a.size();
        lb=b.size();
        if(la>lb) printf("No\n");
        else
        {
            for(i=0,j=0; i<la; i++)
            {
                for(f=0; j<lb; j++)
                {
                    if(a[i]==b[j])
                    {
                        f=1;
                        j++;
                        break;
                    }
                }
                if(f==0) break;
            }
            if(i==la) printf(("Yes\n"));
            else printf("No\n");
        }
    }
    return 0;
}
