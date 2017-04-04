//Dipta Das CUET CSE-11

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define sf scanf
#define pf printf
#define read(n) scanf("%lld",&n)
#define mset(a,s) memset(a,s,sizeof(a))
#define all(a) a.begin(),a.end()
#define pi acos(-1.0)
#define eps 1e-7
#define mod 1073741824
#define inf 1e9
#define nn 300


struct trie
{
    bool endmark;
    LL next[10+1];

    trie()
    {
        endmark=0;
        for(LL i=0; i<10; i++) next[i]=-1;
    }
};

vector<trie> tree;

bool insrt(char *str)
{
    LL node=0,ln=strlen(str);

    for(LL i=0; i<ln; i++)
    {
        LL id=str[i]-'0';

        if(tree[node].next[id]==-1)
        {
            tree[node].next[id]=(LL)tree.size();
            tree.pb(trie());
        }
        else if(i==ln-1) return 0;

        node=tree[node].next[id];

        if(tree[node].endmark) return 0;
    }

    tree[node].endmark=1;

    return 1;
}


int main()
{
    LL tc,n,i;
    char str[50];

    read(tc);

    while(tc--)
    {
        read(n);

        bool tmp=1;

        tree.pb(trie()); //root node

        for(i=0; i<n; i++)
        {
            sf("%s",str);
            if(tmp) tmp=insrt(str);
        }

        if(tmp) pf("YES\n");
        else pf("NO\n");

        tree.clear();
    }
    return 0;
}

