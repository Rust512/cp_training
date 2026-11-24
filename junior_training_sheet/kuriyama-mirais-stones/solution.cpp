#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();

    int n;
    std::cin >> n;

    std::vector<ll> v(n + 1), u(n + 1);

    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        v[i] = 1LL * k;
        u[i] = 1LL * k;
    }

    std::sort(u.begin(), u.end());

    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        u[i] += u[i - 1];
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int type, l, r;
        std::cin >> type >> l >> r;

        ll result = (type == 1) ? v[r] - v[l - 1] : u[r] - u[l - 1];

        std::cout << result << '\n';
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
