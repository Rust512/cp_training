#include <bits/stdc++.h>

void init_io();
std::string repeat(const std::string &, int);

int main() {
    init_io();
    const std::string rainbow("VIBGYOR");

    int n;
    std::cin >> n;
    int rem = n % 7;

    std::string result =
        repeat(rainbow, n / 7).append(rainbow.substr(rem > 3 ? 0 : 3, rem));

    std::cout << result << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

std::string repeat(const std::string &str, int n) {
    if (n <= 0) {
        return "";
    }

    std::string container;
    container.reserve(n * str.length());

    for (int i = 0; i < n; i++) {
        container.append(str);
    }

    return container;
}
