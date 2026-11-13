#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();
    int step, mod;

    while (std::cin >> step >> mod) {
        std::string decision = std::string(4, ' ').append(
            (std::__gcd(step, mod) == 1) ? "Good Choice" : "Bad Choice");
        std::cout << std::setw(10) << step;
        std::cout << std::setw(10) << mod;
        std::cout << decision << "\n\n";
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
