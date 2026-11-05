#include <cmath>
#include <iostream>

void solve(int caseId);

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

    int solvableCount = 0;

    for (int i = 0; i < n; i++) {
        int p, v, t;

        std::cin >> p >> v >> t;

        int totalSolvers = (p + v + t);

        if (totalSolvers > 1) {
            solvableCount++;
        }
    }

    std::cout << solvableCount << '\n';
}
