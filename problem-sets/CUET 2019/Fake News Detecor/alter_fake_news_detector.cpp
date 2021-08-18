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

int cnt[100][26];

bool isCompletelyDifferent(int n) {
    for (int i = 0; i < 26; i++) {
        if (cnt[0][i] && cnt[n - 1][i]) return false;
    }
    return true;
}

bool hasOneChanged(int n) {
    for (int i = 1; i < n; i++) {
        int x = 0, y = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] > cnt[i - 1][j])
                x += cnt[i][j] - cnt[i - 1][j];
            else
                y += cnt[i - 1][j] - cnt[i][j];
        }
        if (max(x, y) > 1) return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output-test.out", "w", stdout);

    ios_base::sync_with_stdio(0), cin.tie(0);

    int t = 0, tc, n;
    string s;

    cin >> tc;

    while (tc--) {
        mset(cnt, 0);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) cnt[i][s[j] - 'a']++;
        }
        if (n > 1 && isCompletelyDifferent(n) && hasOneChanged(n))
            cout << "Case " << ++t << ": Fake News" << endl;
        else
            cout << "Case " << ++t << ": Not Fake News" << endl;
    }

    return 0;
}
