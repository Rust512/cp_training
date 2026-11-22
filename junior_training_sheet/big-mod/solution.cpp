#include <bits/stdc++.h>

typedef uint32_t ui;

void init_io();
ui power_mod(ui, ui, ui);

int main() {
    init_io();
    ui b, p, m;

    while (std::cin >> b >> p >> m) {
        ui result = power_mod(b, p, m);
        std::cout << result << '\n';
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

ui power_mod(ui b, ui p, ui m) {
    b %= m;
    ui result = 1;
    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;
        p >>= 1;
    }

    return result;
}
