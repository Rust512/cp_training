#include <bits/stdc++.h>

void solve(int);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    for (int c = 1; c <= t; c++) {
        solve(c);
    }

    return 0;
}

void solve(int caseId) {
    int a[4] = {};
    int count[4] = {};
    std::string strips;

    for (auto &entry : a) {
        std::cin >> entry;
    }

    std::cin >> strips;

    for (auto &letter : strips) {
        count[letter - '1']++;
    }

    long long sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += 1LL * a[i] * count[i];
    }

    std::cout << sum << '\n';
}
