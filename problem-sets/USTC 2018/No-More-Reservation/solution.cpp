#include <bits/stdc++.h>
#define LL long long
#define NN 100005
#define ALL(v) (v).begin(),(v).end()

using namespace std;

string getColor(LL r, LL g, LL b, LL k)
{
    vector< pair<long long, string> > v;
    v.push_back(make_pair(r, "SNIGDHA"));
    v.push_back(make_pair(g, "SHOVON"));
    v.push_back(make_pair(b, "SHULOV"));

    --k;
    while (k >= v.size())
    {
        LL d = k / v.size();
        d = min(d, min_element(ALL(v))->first);

        for (size_t i = 0; i < v.size(); ++i)
            v[i].first -= d;

        k -= d * v.size();

        vector< pair<long long, string> >:: iterator it;
        while (!(it = min_element(ALL(v)))->first)
            v.erase(it);
    }
    return v[k].second;
}

int main()
{
    //freopen("input.in", "r", stdin);
    //freopen("output-2.out", "w", stdout);

    LL t=1,tc,r,g,b,k;

    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld %lld %lld %lld", &r, &g, &b, &k);
        printf("Case %lld: ",t++);
        cout<<getColor(r,g,b,k)<<endl;
    }
    return 0;
}
