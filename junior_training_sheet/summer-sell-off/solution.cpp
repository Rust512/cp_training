#include <bits/stdc++.h>

typedef long long ll;

void init_io();
ll diff(const std::pair<ll, ll> &);

int main() {
    init_io();

    int n, f;
    std::cin >> n >> f;

    std::vector<std::pair<ll, ll>> shop(n);

    ll sum = 0LL;
    for (auto &x : shop) {
        std::cin >> x.first >> x.second;
        sum += 1LL * std::min(x.first, x.second);
    }

    auto comparator = [](std::pair<ll, ll> a, std::pair<ll, ll> b) {
        return diff(a) > diff(b);
    };
    std::sort(shop.begin(), shop.end(), comparator);

    for (int i = 0; i < f; i++) {
        sum += diff(shop[i]);
    }

    std::cout << sum << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

ll diff(const std::pair<ll, ll> &entry) {
    return std::min(2LL * entry.first, entry.second) -
           std::min(entry.first, entry.second);
}
