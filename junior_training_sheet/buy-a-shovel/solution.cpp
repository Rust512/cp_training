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
    int k, r;
    std::cin >> k >> r;

    int i = 1;
    int u = k % 10;

    while (i < 10) {
        int multiple = u * i;
        if (multiple % 10 == r || multiple % 10 == 0) {
            break;
        }
        i++;
    }

    std::cout << i << '\n';
}
