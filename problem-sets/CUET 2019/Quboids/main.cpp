#include <bits/stdc++.h>
#define INF 999
using namespace std;

int g[50][50];

int main() {
    freopen("input.in", "r", stdin);
    freopen("output-2.out", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int n, m, u, v;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    g[i][j] = 0;
                else
                    g[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            g[u][v] = 1;
            g[v][u] = 1;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) ans = max(ans, g[i][j]);

        if (ans == INF)
            cout << "INFINITY" << endl;
        else
            cout << ans * n << endl;
    }

    return 0;
}
