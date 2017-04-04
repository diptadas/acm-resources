#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int get(char ch)
{
    string s="BUSPFTM";
    for(int i=0; i<7; i++) if(ch==s[i]) return i;
}

int main()
{

    int n;
    cin>>n;

    while(n--)
    {
        string s;
        cin>>s;

        bool tmp=1;

        for(int i=1; i<s.size(); i++)
        {
            if(get(s[i]) > get(s[i-1]))
            {
                tmp=0;
                break;
            }
        }

        if(tmp==0)
        {
            tmp=1;
            for(int i=1; i<s.size(); i++)
            {
                if(get(s[i]) < get(s[i-1]))
                {
                    tmp=0;
                    break;
                }
            }
        }

        if(tmp==1)
        {
            int a[10]= {0};

            for(int i=0; i<s.size(); i++)
            {
                if(a[get(s[i])]==9)
                {
                    tmp=0;
                    break;
                }
                else a[get(s[i])]++;
            }
        }

        if(tmp==0) cout<<"error"<<endl;
        else
        {
            int sum=0;
            for(int i=0; i<s.size(); i++) sum+=(int) pow(10.0,get(s[i]));
            cout<<sum<<endl;
        }
    }
    return 0;
}
