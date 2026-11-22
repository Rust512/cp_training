#include <bits/stdc++.h>

void init_io();

int main() {
    init_io();
    int n;
    std::cin >> n;

    std::string encoding;
    std::cin >> encoding;

    std::deque<char> container;

    for (int i = 0; i < n; i++) {
        if ((n + i) % 2 == 1) {
            container.push_back(encoding[i]);
        } else {
            container.push_front(encoding[i]);
        }
    }

    for (const char &ch : container) {
        std::cout << ch;
    }

    std::cout << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
