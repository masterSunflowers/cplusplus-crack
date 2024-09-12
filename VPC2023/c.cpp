#include <bits/stdc++.h>

using namespace std;

void run_case() {
    int n;
    cin >> n;
    int p[n];
    double avg[n];
    double data;
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i<n; i++) {
        cin >> data;
        avg[i] = data / p[i];
    }
    cout << 1 << '\n' << max_element(avg, avg + n) - avg + 1;
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