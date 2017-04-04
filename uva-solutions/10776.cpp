#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;

char s[31];
bool taken[31];
vector<char> ans;
int l,r;

void call()
{
    if(ans.size()==r)
    {
        for(int i=0; i<r; i++)
            printf("%c",ans[i]);
        puts("");
        return;
    }
    char pre='!';
    for(int i=0; i<l; i++)
    {
        if(taken[i]==0 && s[i]!=pre && (ans.size()==0 || s[i]>=ans.back()))
        {
            ans.push_back(s[i]);
            taken[i]=1;
            call();
            taken[i]=0;
            pre=ans.back();
            ans.pop_back();
        }
    }
}

int main()
{
    while(scanf("%s %d",s,&r)!=EOF)
    {
        memset(taken,0,sizeof(taken));
        ans.clear();
        l=strlen(s);
        sort(s,s+l);
        call();
    }
    return 0;
}

