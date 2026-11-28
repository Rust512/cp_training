#include <bits/stdc++.h>

typedef long long ll;

void init_io();
bool is_uppercase(char);
int dist(const std::pair<int, int> &, const std::pair<int, int> &);

int main() {
    init_io();

    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::string> keyboard(n);
    std::vector<std::pair<int, int>> shift;

    for (auto &row : keyboard) {
        std::cin >> row;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (keyboard[i][j] == 'S') {
                shift.emplace_back(i, j);
            }
        }
    }

    int shift_count = (int)shift.size();
    std::array<int, 26> min_shift_distance;
    min_shift_distance.fill(INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (keyboard[i][j] == 'S') {
                continue;
            }

            int index = keyboard[i][j] - 'a';

            if (shift.empty()) {
                min_shift_distance[index] = 0;
                continue;
            }

            for (int k = 0; k < shift_count; k++) {
                min_shift_distance[index] =
                    std::min(min_shift_distance[index], dist({i, j}, shift[k]));
            }
        }
    }

    int q;
    std::cin >> q;

    std::string t;
    std::cin >> t;

    int count = 0;
    for (const char &ch : t) {
        int lower = std::tolower(ch);
        int index = lower - 'a';

        if (min_shift_distance[index] == INT_MAX ||
            (is_uppercase(ch) && shift.empty())) {
            std::cout << "-1\n";
            return 0;
        }

        if (!is_uppercase(ch)) {
            continue;
        }

        if (min_shift_distance[index] > x * x) {
            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

bool is_uppercase(char ch) { return ch >= 'A' && ch <= 'Z'; }

int dist(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    int x_2 = (a.first - b.first) * (a.first - b.first);
    int y_2 = (a.second - b.second) * (a.second - b.second);

    return x_2 + y_2;
}
