/**
 *    @author     : Dipta Das
 *    @University : CUET CSE 11
 *    @Codeforces : diptadas
 *    @Topcoder   : dipta670
 *    @link       : www.fb.com/dipta.das
 */

#include <bits/stdc++.h>
using namespace std;

int digSum(int n)
{
    int sum = 0;
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int call(string s)
{
    int sum=0;
    bool found[27] = {0};
    for(int i=0; i<s.size(); i++)
    {
        int x = toupper(s[i]) - 'A' + 1;
        if (!found[x])
        {
            sum += x;
            found[x]=1;
        }
    }
    return digSum(sum);
}

int diff(string s1, string s2)
{
    int x=call(s1);
    int y=call(s2);
    return __builtin_popcount(x^y);
}

int main()
{
    //freopen("A.in", "r", stdin);
    freopen("AAA.out", "w", stdout);

    string s1, s2;
    while(cin>>s1>>s2)
    {
        cout << s1 << " - " << s2 << " = " << diff(s1,s2) << endl;
    }

    return 0;
}
