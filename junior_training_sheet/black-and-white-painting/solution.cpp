#include <bits/stdc++.h>

typedef long long ll;

void init_io();
ll count_chess_boards(int, int, int);

int main() {
    init_io();
    int n, m, c;
    while (std::cin >> n >> m >> c) {
        if (n == 0) {
            break;
        }

        ll boards = count_chess_boards(n, m, c);
        std::cout << boards << '\n';
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

ll count_chess_boards(int n, int m, int c) {
    int p = n - 7;
    int q = m - 7;

    if (p % 2 == 0 || q % 2 == 0) {
        return 1LL * p * q / 2LL;
    }

    return (1LL * p * q + (c == 1 ? 1 : -1)) / 2LL;
}