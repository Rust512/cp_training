#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();

    int n, l;
    std::cin >> n >> l;

    std::vector<int> a(n);

    for (int &x : a) {
        std::cin >> x;
    }

    std::sort(a.begin(), a.end());

    double max_rad = std::max(a.front(), l - a.back());
    for (int i = 1; i < n; i++) {
        max_rad = std::max(max_rad, 1.0 * (a[i] - a[i - 1]) / 2.0);
    }

    std::cout << std::fixed << std::setprecision(10) << max_rad << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
