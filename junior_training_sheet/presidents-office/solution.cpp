#include <bits/stdc++.h>

typedef long long ll;

const int DIRS = 4;
const std::array<int, 4> DX = {-1, 0, 1, 0};
const std::array<int, 4> DY = {0, 1, 0, -1};

void init_io();
bool is_valid(int, int, int, int);
std::array<int, 26> bfs(int, int, char, const std::vector<std::string> &);

int main() {
    init_io();

    int n, m;
    std::string color;

    std::cin >> n >> m >> color;

    char ch = color[0];

    std::vector<std::string> floor(n);

    for (std::string &x : floor) {
        std::cin >> x;
    }

    int r_start = -1;
    int c_start = -1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (floor[r][c] == ch) {
                r_start = r;
                c_start = c;
                break;
            }
        }

        if (r_start != -1) {
            break;
        }
    }

    auto freq = bfs(r_start, c_start, ch, floor);

    int count_adj = 0;
    for (const int &val : freq) {
        if (val != 0) {
            count_adj++;
        }
    }

    std::cout << count_adj << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

bool is_valid(int row, int col, int n, int m) {
    return (row >= 0 && row < n) && (col >= 0 && col < m);
}

std::array<int, 26> bfs(int row, int col, char c,
                        const std::vector<std::string> &floor) {
    std::array<int, 26> freq{};
    std::queue<std::pair<int, int>> container;
    container.push({row, col});

    int n = floor.size();
    int m = floor[0].size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));

    while (!container.empty()) {
        auto top = container.front();
        container.pop();

        if (visited[top.first][top.second]) {
            continue;
        }

        visited[top.first][top.second] = true;

        for (int i = 0; i < DIRS; i++) {
            int new_r = top.first + DX[i];
            int new_c = top.second + DY[i];

            if (!is_valid(new_r, new_c, n, m)) {
                continue;
            }

            char cell = floor[new_r][new_c];
            if (visited[new_r][new_c] || cell == '.') {
                continue;
            }

            if (cell == c) {
                container.push({new_r, new_c});
            } else {
                freq[cell - 'A']++;
            }
        }
    }

    return freq;
}
