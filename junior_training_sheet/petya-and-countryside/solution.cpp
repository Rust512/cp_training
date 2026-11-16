#include <bits/stdc++.h>

typedef long long ll;

void init_io();
void solve(int);
bool analyze(ll, ll, const std::vector<ll> &);

int main() {
    init_io();
    int n;
    std::cin >> n;

    std::vector<int> garden(n);

    for (int &x : garden) {
        std::cin >> x;
    }

    std::vector<int> count(n);

    int counter = 0;
    for (int i = 1; i < n; i++) {
        if (garden[i] >= garden[i - 1]) {
            counter++;
        } else {
            counter = 0;
        }
        count[i] += counter;
    }

    counter = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (garden[i] >= garden[i + 1]) {
            counter++;
        } else {
            counter = 0;
        }
        count[i] += counter;
    }

    int max_watered = 1 + *std::max_element(count.begin(), count.end());

    std::cout << max_watered << '\n';
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
