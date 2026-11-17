#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> arr(m);

    for (auto &entry : arr) {
        std::cin >> entry.second >> entry.first;
    }

    auto comparator = [](auto a, auto b) { return a.first > b.first; };
    std::sort(arr.begin(), arr.end(), comparator);

    int i = 0;
    ll matches = 0LL;
    while (n > 0 && i < m) {
        int min_val = std::min(arr[i].second, n);
        n -= min_val;
        matches += 1LL * min_val * arr[i].first;
        i++;
    }

    std::cout << matches << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
