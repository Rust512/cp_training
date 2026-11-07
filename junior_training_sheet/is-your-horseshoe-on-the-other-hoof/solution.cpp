#include <bits/stdc++.h>
#include <unordered_set>

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
    std::unordered_set<int> set;

    for (int i = 0; i < 4; i++) {
        int color;
        std::cin >> color;
        set.insert(color);
    }

    std::cout << (4 - set.size()) << '\n';
}
