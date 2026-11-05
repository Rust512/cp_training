#include <cstdlib>
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
    int oneRow = -1;
    int oneCol = -1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int entry;
            std::cin >> entry;

            if (entry == 1) {
                oneRow = i;
                oneCol = j;
                break;
            }
        }

        if (oneRow != -1) {
            break;
        }
    }

    int totalSwaps = std::abs(oneRow - 2) + std::abs(oneCol - 2);

    std::cout << totalSwaps << '\n';
}
