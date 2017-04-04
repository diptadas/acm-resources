//Dipta Das CUET CSE-11

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <set>

#define LL long long
#define Pi acos(-1.0)
#define EPS 1e-11
#define mset(a, s) memset(a, s, sizeof (a))

using namespace std;


int main()
{
    int tc;
    vector< pair<int,string> > store;

    scanf("%d",&tc);
    getchar();

    while(tc--)
    {
        getchar();

        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        stringstream ss1(s1), ss2(s2);

        int index;
        string value;

        while(ss1>>index)
        {
            ss2>>value;
            store.push_back(make_pair(index,value));
        }

        sort(store.begin(),store.end());
        for (int i=0; i<store.size(); i++) cout<<store[i].second<<endl;

        store.clear();
        if(tc) puts("");
    }
    return 0;
}

