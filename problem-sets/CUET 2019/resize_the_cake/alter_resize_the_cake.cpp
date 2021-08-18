/**
 *    @author     : Dipta Das
 *    @Codeforces : diptadas
 *    @link       : diptadas.com
 */

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pll pair<LL, LL>
#define mp make_pair
#define fr first
#define sc second
#define pb push_back

#define read(n) scanf("%lld", &n)
#define mset(a, s) memset(a, s, sizeof(a))
#define all(a) a.begin(), a.end()

#define PI acos(-1.0)
#define EPS 1e-9
#define MOD 1000000007
#define INF 1e9
#define NN 1000009

struct p  //point
{
    double x, y;
    p(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
};

p mv(p a, p b)  //make vector
{
    return p(b.x - a.x, b.y - a.y);
}

double dp(p a, p b)  //dot product
{
    return a.x * b.x + a.y * b.y;
}

p add(p a, p b)  //two vector add
{
    return p(a.x + b.x, a.y + b.y);
}

double value(p a)  //value of a vector
{
    return sqrt(dp(a, a));
}

p lv(p a, double l)  //l th time of a vector
{
    double v = value(a);
    return p((a.x * l) / v, (a.y * l) / v);
}

p pointseg(p a, p b, p c)  //min distance point of a,b segment from point c
{
    if (dp(mv(a, b), mv(a, c)) < 0) return a;
    if (dp(mv(b, a), mv(b, c)) < 0) return b;
    double l = (dp(mv(a, b), mv(a, c))) / value(mv(a, b));
    return add(a, lv(mv(a, b), l));
}

double dis(p a, p b)  //distance of two point
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    // freopen("input_large.txt", "r", stdin);
    // freopen("output-test.out", "w", stdout);

    // ios_base::sync_with_stdio(0), cin.tie(0);

    int tc;
    double cx, cy, r, x1, y1, x2, y2, minDis, ans;
    cin >> tc;

    while (tc--) {
        cin >> cx >> cy >> r;
        cin >> x1 >> y1 >> x2 >> y2;

        double minDis = dis(pointseg(p(x1, y1), p(x2, y2), p(cx, cy)), p(cx, cy));

        if (minDis > r)
            ans = r + r;
        else
            ans = minDis + r;

        printf("%.6lf\n", ans);
    }

    return 0;
}
