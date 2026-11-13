#include <iostream>
#include <cstdint>

void solve(uint64_t);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint64_t k;

    while (true) {
        std::cin >> k;
        if (k == 0) {
            break;
        }
        solve(k);
    }

    return 0;
}

void solve(uint64_t num) {
    bool evenDivisors = false;
    for (uint64_t i = 2; i * i <= num; i++) {
        if (num % i != 0) {
            continue;
        }

        int count = 0;
        while (num % i == 0) {
            num /= i;
            count++;
        }

        if (count % 2 == 1) {
            evenDivisors = true;
        }
    }

    if (num > 1) {
        evenDivisors = true;
    }

    std::string result = evenDivisors ? "no" : "yes";
    std::cout << result << '\n';
}
