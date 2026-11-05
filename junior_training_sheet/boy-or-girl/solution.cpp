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
    std::string name;

    std::cin >> name;

    int freq[26] = {0};

    for (auto ch : name) {
        freq[ch - 'a']++;
    }

    int countUnique = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            countUnique++;
        }
    }

    bool isGirl = (countUnique % 2 == 0);

    std::cout << (isGirl ? "CHAT WITH HER!" : "IGNORE HIM!") << '\n';
}
