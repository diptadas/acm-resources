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
bool taken[55];
string a[5]= {"235","135","1245","35","1234"};
vector<int> ans;

void call()
{
    if(ans.size()==9)
    {
        for(int i=0; i<9; i++) printf("%d",ans[i]);
        puts("");
        return;
    }

    int p=ans.back();

    for(int i=0; i<a[p-1].size(); i++)
    {
        int t,q=a[p-1][i]-'0';
        if(p>q) t=p*10+q;
        else t=q*10+p;

        if(taken[t]==0)
        {
            taken[t]=1;
            ans.push_back(q);
            call();
            taken[t]=0;
            ans.pop_back();
        }
    }
}

int main()
{
    ans.push_back(1);
    call();
    return 0;
}

