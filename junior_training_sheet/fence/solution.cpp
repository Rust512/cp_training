#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();

    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n + 1);

    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        h[i] = k + h[i - 1];
    }

    int min_start = -1;
    int min_sum = h.back() + 1;
    for (int i = k; i <= n; i++) {
        int start = i - k;
        int diff = h[i] - h[start];

        if (diff < min_sum) {
            min_sum = diff;
            min_start = start + 1;
        }
    }

    std::cout << min_start << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
