#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (c < a) {
        std::cout << a << '\n';
        return 0;
    }
    int haggles = (c - a) / (b + d);
    if ((c - a) % (b + d) != 0) {
        haggles++;
    }

    std::cout << std::min(a + haggles * b, c - (haggles - 1) * d) << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
