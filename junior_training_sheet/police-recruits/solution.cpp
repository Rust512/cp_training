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

    int availableRecruits = 0;
    int crimes = 0;

    for (int i = 0; i < n; i++) {
        int entry;

        std::cin >> entry;

        if (entry > -1) {
            availableRecruits += entry;
            continue;
        }

        if (availableRecruits == 0) {
            crimes++;
        } else {
            availableRecruits--;
        }
    }

    std::cout << crimes << '\n';
}
