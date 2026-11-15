#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();

    int n;
    std::cin >> n;

    std::vector<int> map(n);
    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        map[k - 1] = i;
    }

    for (const auto &val : map) {
        std::cout << val << ' ';
    }

    std::cout << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
