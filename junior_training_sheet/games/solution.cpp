#include <array>
#include <bits/stdc++.h>
#include <cstdlib>

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
    std::array<int, 100> h{}, a{};
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int home, guest;
        std::cin >> home >> guest;

        h[home - 1]++;
        a[guest - 1]++;
    }

    int count = 0;
    for (int i = 0; i < 100; i++) {
        count += (h[i] * a[i]);
    }

    std::cout << count << '\n';
}
