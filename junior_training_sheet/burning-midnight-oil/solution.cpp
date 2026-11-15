#include <bits/stdc++.h>

typedef long long ll;

void init_io();
ll calculate(int, int);

int main() {
    init_io();

    int n, k;
    std::cin >> n >> k;

    int start = 1;
    int end = n;
    int target = 1LL * n;
    int result = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        ll midVal = calculate(mid, k);

        if (midVal >= target) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    std::cout << result << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

ll calculate(int v, int k) {
    ll mul = 1;
    ll sum = 0LL;

    while (mul <= v) {
        sum += 1LL * std::floor(v / mul);
        mul *= 1LL * k;
    }

    return sum;
}
