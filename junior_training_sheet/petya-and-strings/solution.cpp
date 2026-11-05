#include <bits/stdc++.h>

void solve(int);
int compare(char, char);
int sign(int);

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
    std::string str1, str2;

    std::cin >> str1 >> str2;

    for (int i = 0; i < str1.length(); i++) {
        int comparison = compare(str1[i], str2[i]);
        if (comparison != 0) {
            std::cout << comparison << '\n';
            return;
        }
    }

    std::cout << 0 << '\n';
}

int sign(int x) {
    if (x == 0) {
        return 0;
    }

    if (x > 0) {
        return 1;
    }

    return -1;
}

int compare(char ch1, char ch2) {
    if (ch1 < 'a') ch1 += 32;
    if (ch2 < 'a') ch2 += 32;

    return sign(ch1 - ch2);
}
