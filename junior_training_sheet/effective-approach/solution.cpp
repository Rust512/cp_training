#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();
    int n;
    std::cin >> n;

    std::vector<int> map(n + 1);
    map[0] = 0;

    for (int i = 1; i <= n; i++) {
        int entry;
        std::cin >> entry;
        map[entry] = i;
    }

    int m;
    std::cin >> m;

    ll v = 0LL, p = 0LL;
    for (int i = 0; i < m; i++) {
        int query;
        std::cin >> query;

        v += 1LL * map[query];
        p += 1LL * (n + 1 - map[query]);
    }

    std::cout << v << ' ' << p << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
