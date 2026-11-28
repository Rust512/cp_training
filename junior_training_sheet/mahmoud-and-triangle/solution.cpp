#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int &x : a) {
        std::cin >> x;
    }

    std::sort(a.begin(), a.end());

    bool possible = false;
    for (int i = 2; i < n; i++) {
        if (a[i] < a[i - 1] + a[i - 2]) {
            possible = true;
            break;
        }
    }

    std::string result = possible ? "YES" : "NO";

    std::cout << result << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
