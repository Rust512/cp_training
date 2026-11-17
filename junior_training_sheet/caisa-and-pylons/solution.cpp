#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();
    int n;
    std::cin >> n;

    std::vector<int> h(n + 1);
    h[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        std::cin >> h[i];
    }

    int min_delta = 1e6;
    int delta = 0;
    for (int i = 0; i < n; i++) {
        delta += (h[i] - h[i + 1]);
        min_delta = std::min(min_delta, delta);
    }

    int result = -min_delta;

    std::cout << result << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
