#include <bits/stdc++.h>

typedef unsigned long long ull;
const int N = 5;

void init_io();

void solve(int);
ull lcm(std::initializer_list<ull>);
ull lcm(ull, ull);
ull divisible_between(ull, ull, ull);
ull sum_intersection_1(std::array<ull, N>, ull, ull);
ull sum_intersection_2(std::array<ull, N>, ull, ull);
ull sum_intersection_3(std::array<ull, N>, ull, ull);
ull sum_intersection_4(std::array<ull, N>, ull, ull);
ull sum_intersection_5(std::array<ull, N>, ull, ull);

int main() {
    init_io();
    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(int case_id) {
    ull n, m, a, d;
    std::cin >> n >> m >> a >> d;

    std::array<ull, N> ap;

    for (int i = 0; i < N; i++) {
        ap[i] = a * 1ULL + i * d * 1ULL;
    }

    ull i1 = sum_intersection_1(ap, n, m);
    ull i2 = sum_intersection_2(ap, n, m);
    ull i3 = sum_intersection_3(ap, n, m);
    ull i4 = sum_intersection_4(ap, n, m);
    ull i5 = sum_intersection_5(ap, n, m);

    ull result = i1 - i2 + i3 - i4 + i5;
    ull total_numbers = m - n + 1;
    std::cout << (total_numbers - result) << '\n';
}

ull lcm(std::initializer_list<ull> list) {
    std::vector<ull> args(list);
    int size = args.size();

    ull overall_lcm = args[0];
    for (int i = 1; i < size; i++) {
        args[i] = lcm(args[i], args[i - 1]);
    }

    return args.back();
}

ull lcm(ull num1, ull num2) { return (num1 / std::__gcd(num1, num2)) * num2; }

ull divisible_between(ull n, ull m, ull k) {
    return (m / k) - ((n - 1ULL) / k);
}

ull sum_intersection_1(std::array<ull, N> ap, ull n, ull m) {
    ull sum = 0ULL;
    for (int i = 0; i < N; i++) {
        ull divisor = lcm({ap[i]});
        sum += divisible_between(n, m, divisor);
    }

    return sum;
}

ull sum_intersection_2(std::array<ull, N> ap, ull n, ull m) {
    ull sum = 0ULL;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ull divisor = lcm({ap[i], ap[j]});
            sum += divisible_between(n, m, divisor);
        }
    }

    return sum;
}

ull sum_intersection_3(std::array<ull, N> ap, ull n, ull m) {
    ull sum = 0ULL;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ull divisor = lcm({ap[i], ap[j], ap[k]});
                sum += divisible_between(n, m, divisor);
            }
        }
    }

    return sum;
}

ull sum_intersection_4(std::array<ull, N> ap, ull n, ull m) {
    ull sum = 0ULL;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int p = k + 1; p < N; p++) {
                    ull divisor = lcm({ap[i], ap[j], ap[k], ap[p]});
                    sum += divisible_between(n, m, divisor);
                }
            }
        }
    }

    return sum;
}

ull sum_intersection_5(std::array<ull, N> ap, ull n, ull m) {
    return divisible_between(n, m, lcm({ap[0], ap[1], ap[2], ap[3], ap[4]}));
}
