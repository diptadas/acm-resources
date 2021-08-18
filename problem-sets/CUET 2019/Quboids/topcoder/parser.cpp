#include <bits/stdc++.h>
#define LL long long
using namespace std;

string s[50];
vector<pair<int, int>> v;

int main() {
    freopen("input-raw.in", "r", stdin);

    int t = 0;

    while (cin >> s[0]) {
        int n = s[0].size();
        for (int i = 1; i < n; i++) cin >> s[i];

        int d, mx;
        cin >> d >> mx;

        v.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i][j] == 'Y') v.push_back(make_pair(i + 1, j + 1));
            }
        }

        int m = v.size();
        //cout << n << " " << m << endl;
        for (int i = 0; i < m; i++) {
            //cout << v[i].first << " " << v[i].second << endl;
        }

        if (mx != -1 && d != 0) {
            mx /= d;
            mx *= n;
        }
        if (d == 0) mx = 999;

        cout << mx << endl;

        t++;
    }

    //cout << "#" << t << endl;
    return 0;
}
