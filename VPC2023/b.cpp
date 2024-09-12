#include <bits/stdc++.h>

using namespace std;

void run_case() {
    int t;
    cin >> t;
    long long c, m, n;
    map<long long, long long> points;
    for (int k=0; k<t; k++) {
        cin >> c >> m >> n;
        long long s, x, d;
        for (int i=0; i<m; i++) {
            cin >> s;
            points[s] = 0;
        }
        for (int i=0; i<n; i++) {
            cin >> x >> d;
            points[x] = d;
        }
        long long cur = c;
        long long res = 0;
        for (auto [u, v]: points) {
            if (v == 0) {
                cur = c;
            } else {
                if (cur >= v) {
                    cur -= v;
                    res += v;
                }
            }
        }
        cout << res << '\n';
        points.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    run_case();
    return 0;
}