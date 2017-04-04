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
    string s;

    while(cin>>s)
    {
        int pre=0,tmp;
        for(int i=0; i<s.size(); i++)
        {
            char ch=s[i];
            if(ch=='B'||ch=='F'||ch=='P'||ch=='V') tmp=1;
            else if(ch=='C'||ch=='G'||ch=='J'||ch=='K'||ch=='Q'||ch=='X'||ch=='S'||ch=='Z') tmp=2;
            else if(ch=='D'||ch=='T') tmp=3;
            else if(ch=='L') tmp=4;
            else if(ch=='M'||ch=='N') tmp=5;
            else if(ch=='R') tmp=6;
            else
            {
                pre=0;
                continue;
            }

            if(pre!=tmp) pre=tmp,printf("%c",tmp+'0');
        }
        puts("");
    }
    return 0;
}


