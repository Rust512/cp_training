#include <bits/stdc++.h>

typedef long long ll;

void init_io();
void solve(int);
bool analyze(ll, ll, const std::vector<ll> &);

int main() {
    init_io();
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(int case_id) {
    ll n, c;
    std::cin >> n >> c;

    std::vector<ll> stalls(n);

    for (ll &x : stalls) {
        std::cin >> x;
    }

    std::sort(stalls.begin(), stalls.end());

    ll start = 1LL;
    ll end = (stalls.back() - stalls.front()) / (c - 1LL);
    ll result = 0LL;

    while (start <= end) {
        ll mid = start + (end - start) / 2LL;
        bool possible = analyze(mid, c - 1LL, stalls);

        if (possible) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    std::cout << result << '\n';
}

bool analyze(ll diff, ll cows, const std::vector<ll> &stalls) {
    int start = 0;
    while (cows > 0LL) {
        auto result = std::lower_bound(stalls.begin() + start, stalls.end(),
                                       stalls[start] + diff);

        if (result == stalls.end()) {
            return false;
        }

        cows--;
        start = result - stalls.begin();
    }

    return true;
}
