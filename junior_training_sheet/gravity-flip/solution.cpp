#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

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

    auto boxes = std::vector<int>(n);

    for (int &x : boxes) {
        std::cin >> x;
    }

    std::sort(boxes.begin(), boxes.end());

    for (auto x : boxes) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}
