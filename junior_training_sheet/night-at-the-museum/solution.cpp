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
    std::string word;

    std::cin >> word;

    word = 'a' + word;

    int rotations = 0;
    for (int i = 1; i < word.length(); i++) {
        int counterRotations = std::abs(word[i] - word[i - 1]);
        rotations += std::min(counterRotations, 26 - counterRotations);
    }

    std::cout << rotations << '\n';
}
