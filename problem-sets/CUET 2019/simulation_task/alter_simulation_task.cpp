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

string replaceAll(string s, string search, string replace) {
    for (size_t pos = 0;; pos += replace.length()) {
        pos = s.find(search, pos);
        if (pos == string::npos)
            break;
        s.erase(pos, search.length());
        s.insert(pos, replace);
    }
    return s;
}

string replaceAtStart(string s, string search, string replace) {
    if (s.find(search) == 0) {
        s.erase(0, search.length());
        s.insert(0, replace);
    }
    return s;
}

bool isConsonant(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    return true;
}

string s1(string s) {
    if (s[0] == 'x')
        s[0] = 'z';
    return replaceAll(s, "x", "ks");
}

string s2(string s) {
    s = s1(s);

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'y')
            s[i] = 'i';

    return s;
}

string s3(string s) {
    s = s2(s);

    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == 'c' && (s[i + 1] == 'e' || s[i + 1] == 'i'))
            s[i] = 's';

    return s;
}

string s4(string s) {
    s = s3(s);
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'k') {
            int c = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] != 'c')
                    break;
                c++;
            }
            s.erase(i + 1, c);
        }
    }

    reverse(s.begin(), s.end());
    return s;
}

string s5(string s) {
    s = s4(s);
    s = replaceAtStart(s, "sch", "sk");
    s = replaceAll(s, "chr", "kr");

    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'c' && (i + 1 == s.size() || s[i + 1] != 'h'))
            s[i] = 'k';

    return s;
}

string s6(string s) {
    s = s5(s);
    s = replaceAtStart(s, "kn", "n");
    return s;
}

string s7(string s) {
    s = s6(s);

    for (int i = 0; i < s.size() - 1; i++) {
        if (isConsonant(s[i])) {
            int c = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] != s[i])
                    break;
                c++;
            }
            s.erase(i + 1, c);
        }
    }

    return s;
}

string convert(string s, int step) {
    switch (step) {
        case 1:
            s = s1(s);
            break;
        case 2:
            s = s2(s);
            break;
        case 3:
            s = s3(s);
            break;
        case 4:
            s = s4(s);
            break;
        case 5:
            s = s5(s);
            break;
        case 6:
            s = s6(s);
            break;
        case 7:
            s = s7(s);
            break;
    }
    return s;
}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output-test.out", "w", stdout);

    // ios_base::sync_with_stdio(0), cin.tie(0);

    int t = 0, tc, step;
    char ch;
    string str;
    vector<string> words;

    cin >> tc;

    while (tc--) {
        getchar();

        str = "";
        words.clear();

        while (true) {
            ch = getchar();
            if (ch == '\n') {
                if (str != "") words.pb(str);
                break;
            }
            if (ch == ' ') {
                if (str != "") words.pb(str);
                words.pb(" ");
                str = "";
            } else
                str += ch;
        }
        cin >> step;

        cout << "Case #" << ++t << ": ";

        for (int i = 0; i < words.size(); i++) {
            cout << convert(words[i], step);
        }

        cout << endl;
    }

    return 0;
}
