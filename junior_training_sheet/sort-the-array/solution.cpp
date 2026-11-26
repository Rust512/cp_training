#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();

    int n;
    std::cin >> n;

    std::vector<int> a(n + 2);
    a[0] = 0;

    int max_val = -1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        max_val = std::max(max_val, a[i]);
    }

    a[n + 1] = max_val + 1;

    int count = 1;
    bool impossible = false;
    std::vector<std::pair<int, int>> dec;

    for (int i = 1; i < n + 2; i++) {
        if (a[i] < a[i - 1]) {
            count++;
            continue;
        }

        if (count == 1) {
            continue;
        }

        int start = i - count;
        int end = i - 1;

        if (a[end] < a[start - 1] || a[start] > a[i]) {
            impossible = true;
            break;
        }

        dec.emplace_back(std::make_pair(start, end));
        count = 1;
    }

    if (dec.size() > 1 || impossible) {
        std::cout << "no\n";
        return 0;
    }

    if (dec.empty()) {
        std::cout << "yes\n1 1\n";
        return 0;
    }

    std::cout << "yes\n" << dec[0].first << ' ' << dec[0].second << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
