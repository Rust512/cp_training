#include <bits/stdc++.h>

typedef long long ll;

void init_io();
bool valid(int, int);

int main() {
    init_io();
    int n, a;
    std::cin >> n >> a;
    a--;

    std::vector<int> t(n);

    for (int &x : t) {
        std::cin >> x;
    }

    int caught = t[a];
    int limit = std::max(a, n - 1 - a);

    for (int d = 1; d <= limit; d++) {
        int left = a - d;
        int right = a + d;
        int cities = 0;
        int criminals = 0;

        if (valid(left, n)) {
            cities++;
            criminals += t[left];
        }

        if (valid(right, n)) {
            cities++;
            criminals += t[right];
        }

        if (cities == criminals) {
            caught += criminals;
        }
    }

    std::cout << caught << '\n';
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

bool valid(int index, int size) {
    return index >= 0 && index < size;
}
