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

    std::cin >> n;

    std::string prev;

    std::cin >> prev;

    int groupCount = 1;

    for (int i = 0; i < n - 1; i++) {
        std::string curr;
        std::cin >> curr;

        if (curr[0] != prev[0]) {
            groupCount++;
        }

        prev = curr;
    }

    std::cout << groupCount << '\n';
}
