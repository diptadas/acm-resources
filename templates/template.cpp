// Author: Dipta Das
// Link: https://diptadas.com/

#include <bits/stdc++.h>
using namespace std;

// g++ -d dipta main.cpp && cat input.txt | ./a.out

// ============================DEBUG============================
#ifdef dipta
#include "prettyprint.hpp"
#define dbg(...)                        \
    cout << "# " << __LINE__ << " :: "; \
    _print_out(#__VA_ARGS__, __VA_ARGS__);
template <typename T>
void _print_out(const char* name, T&& arg1) {
    cout << name << " = " << arg1 << endl;
}
template <typename T1, typename... Args>
void _print_out(const char* names, T1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " = " << arg1 << " | ";
    _print_out(comma + 1, args...);
}
template <typename T>
void _print_out(const char* name, T a[], int n) {
    cout << name << " = " << pretty_print_array(a, n) << endl;
}
#else
#define dbg(args...)
#endif
// ==========================END DEBUG==========================

#define ll long long
#define pll pair<ll, ll>
#define fr first
#define sc second
#define pb push_back

#define mem(a, s) memset(a, s, sizeof(a))
#define all(a) a.begin(), a.end()

#define PI acos(-1.0)
#define EPS 1e-9
#define MOD 1000000007
#define INF 1e9
#define NN 200001

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(0),cin.tie(0);

    ll t, tc, n, m, i, j, k;

    vector<ll> a = {1, 2, 3};
    pll b = {4, 5};

    dbg(tc, a, b);

    return 0;
}
