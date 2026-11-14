#include <bits/stdc++.h>
#include <stack>

const int DIRS = 8;
const std::array<int, DIRS> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
const std::array<int, DIRS> dy = {0, 1, 1, 1, 0, -1, -1, -1};

void init_io();
void solve(int, int);
void explore(int, int, int, const std::vector<std::string> &,
             std::vector<std::vector<bool>> &);
bool valid(int, int, int);

int main() {
    init_io();

    int n;
    int count = 1;
    while (std::cin >> n) {
        solve(n, count++);
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(int n, int image_id) {
    std::vector<std::string> pixel(n);
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    for (auto &x : pixel) {
        std::cin >> x;
    }

    int count = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (pixel[r][c] == '0' || visited[r][c]) {
                continue;
            }
            explore(r, c, n, pixel, visited);
            count++;
        }
    }

    std::cout << "Image number " << image_id << " contains " << count
              << " war eagles.\n";
}

void explore(int row, int col, int n, const std::vector<std::string> &pixel,
             std::vector<std::vector<bool>> &visited) {
    std::stack<std::pair<int, int>> container;
    container.push({row, col});

    while (!container.empty()) {
        auto current = container.top();
        container.pop();

        if (visited[current.first][current.second]) {
            continue;
        }

        visited[current.first][current.second] = true;

        for (int d = 0; d < DIRS; d++) {
            int new_row = current.first + dx[d];
            int new_col = current.second + dy[d];

            if (!valid(new_row, new_col, n) || visited[new_row][new_col] ||
                pixel[new_row][new_col] == '0') {
                continue;
            }

            container.push({new_row, new_col});
        }
    }
}

bool valid(int row, int col, int n) {
    return (row >= 0 && row < n && col >= 0 && col < n);
}
