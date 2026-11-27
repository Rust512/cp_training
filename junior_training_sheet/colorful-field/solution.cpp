#include <bits/stdc++.h>

typedef long long ll;

void init_io();
int minimum_greater(int, int, const std::vector<int> &);

int main() {
    init_io();

    int n, m, k, t;
    std::cin >> n >> m >> k >> t;

    std::array<std::string, 3> crops{"Carrots", "Kiwis", "Grapes"};
    std::vector<int> waste(k);

    for (int i = 0; i < k; i++) {
        int wr, wc;
        std::cin >> wr >> wc;
        waste[i] = m * (wr - 1) + (wc - 1);
    }

    std::sort(waste.begin(), waste.end());

    for (int i = 0; i < t; i++) {
        int qr, qc;
        std::cin >> qr >> qc;

        int query = (qr - 1) * m + (qc - 1);
        int index = minimum_greater(k, query, waste);

        std::string result =
            (waste[index] == query) ? "Waste" : crops[(query - index) % 3];

        std::cout << result << '\n';
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int minimum_greater(int n, int target, const std::vector<int> &a) {
    int start = 0;
    int end = n - 1;
    int result = n;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int midVal = a[mid];

        if (midVal >= target) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}
