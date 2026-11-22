#include <bits/stdc++.h>

typedef long long ll;

void init_io();
ll combinations(int, int);

int main() {
    init_io();
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0)
            break;
        ll result = combinations(n, m);
        std::cout << n << " things taken " << m << " at a time is " << result
                  << " exactly.\n";
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

ll combinations(int n, int m) {
    if (m == n) {
        return 1;
    }
    ll res = 1LL;
    int den = 2;
    m = std::min(m, n - m);

    for (int i = n; i > n - m; i--) {
        res *= 1LL * i;
        while (den <= m && res % den == 0) {
            res /= den;
            den++;
        }
    }

    return res;
}
