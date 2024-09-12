#include <bits/stdc++.h>

using namespace std;

void run_case() {
    int r, c;
    cin >> r >> c;
    char mtx[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mtx[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c - 2; j++) {
            if (mtx[i][j] == '.' && mtx[i][j+1] == '.' && mtx[i][j+2] == '.') {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return;
            }
        }
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