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
    int n;
    std::string stones;

    std::cin >> n >> stones;

    int count = 0;

    for (int i = 1; i < n; i++) {
        if (stones[i] == stones[i - 1]) {
            count++;
        }
    }

    std::cout << count << '\n';
}
