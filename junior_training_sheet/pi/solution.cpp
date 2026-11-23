#include <bits/stdc++.h>
#include <iomanip>

typedef long long ll;

void init_io();

int main() {
    init_io();

    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        std::vector<int> data(n);

        for (int &x : data) {
            std::cin >> x;
        }

        int co_prime_pairs = 0;
        for (int r = 1; r < n; r++) {
            for (int l = 0; l < r; l++) {
                if (std::__gcd(data[l], data[r]) == 1) {
                    co_prime_pairs++;
                }
            }
        }

        if (co_prime_pairs == 0) {
            std::cout << "No estimate for this data set.\n";
            continue;
        }

        double pi = std::sqrt(3.0 * n * (n - 1.0) / co_prime_pairs);
        std::cout << std::fixed << std::setprecision(6) << pi << '\n';
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
