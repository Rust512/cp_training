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

    auto arr = std::vector<int>(n);

    for (auto &x : arr) {
        std::cin >> x;
    }

    int start = 0;
    int end = n - 1;

    int s = 0;
    int d = 0;

    for (int turn = 0; turn < n; turn++) {
        int startVal = arr[start];
        int endVal = arr[end];

        if (turn % 2 == 0) {
            if (startVal > endVal) {
                s += startVal;
                start++;
            } else {
                s += endVal;
                end--;
            }

            continue;
        }

        if (startVal > endVal) {
            d += startVal;
            start++;
        } else {
            d += endVal;
            end--;
        }
    }

    std::cout << s << ' ' << d << '\n';
}
