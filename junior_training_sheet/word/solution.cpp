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
    std::string word;

    std::cin >> word;

    int n = word.length();
    int upperCaseCount = 0;

    for (auto letter : word) {
        if (letter < 'a') {
            upperCaseCount++;
        }
    }

    bool convertToUpperCase = (2 * upperCaseCount > n);

    for (auto &letter : word) {
        if (letter >= 'a' && convertToUpperCase) {
            letter -= 32;
            continue;
        }

        if (letter < 'a' && !convertToUpperCase) {
            letter += 32;
        }
    }

    std::cout << word << '\n';
}
