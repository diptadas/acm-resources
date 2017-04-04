#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n,m,s,i,j,r,c;
    char o;
    while(1)
    {
        cin>>n>>m>>s;
        char a[n][m+1];
        char cmd[s+1];
        if(n==0 && m==0 && s==0) break;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            for(j=0; j<n; j++)
            {
                char ch=a[i][j];
                if(ch=='N'||ch=='S'||ch=='L'||ch=='O') r=i,c=j,o=ch;
            }
        }

        cin>>cmd;
        int count=0;

        for(i=0; i<s; i++)
        {
            if(cmd[i]=='D')
            {
                if(o=='N') o='L';
                else if(o=='S') o='O';
                else if(o=='L') o='S';
                else if(o=='O') o='N';
            }
            else if(cmd[i]=='E')
            {
                if(o=='N') o='O';
                else if(o=='S') o='L';
                else if(o=='L') o='N';
                else if(o=='O') o='S';
            }
            else if(cmd[i]=='F')
            {
                if(o=='N')
                {
                    if(r>0 && a[r-1][c]!='#') r--;
                }
                else if(o=='S')
                {
                    if(r<n-1 && a[r+1][c]!='#') r++;
                }
                else if(o=='L')
                {
                    if(c<m-1 && a[r][c+1]!='#') c++;
                }
                else if(o=='O')
                {
                    if(c>0 && a[r][c-1]!='#') c--;
                }
            }

            if(a[r][c]=='*') count++,a[r][c]='.';
        }
        cout<<count<<endl;
    }

    return 0;
}
