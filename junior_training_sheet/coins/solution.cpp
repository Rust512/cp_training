#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

void init_io();
bool set(char, char, std::array<std::pair<int, int>, 3> &);

int main() {
    init_io();
    std::array<pii, 3> map;

    for (int i = 0; i < 3; i++) {
        map[i] = {i, 0};
    }

    for (int i = 0; i < 3; i++) {
        std::string comp;
        std::cin >> comp;

        if (comp[1] == '<') {
            map[comp[2] - 'A'].second++;
        } else {
            map[comp[0] - 'A'].second++;
        }
    }

    bool impossible = map[0].second == map[1].second;

    if (impossible) {
        std::cout << "Impossible\n";
        return 0;
    }

    auto comparator = [](pii a, pii b) { return a.second < b.second; };
    std::sort(map.begin(), map.end(), comparator);

    std::string result;
    for (int i = 0; i < 3; i++) {
        result.push_back((char)('A' + map[i].first));
    }

    std::cout << result << '\n';
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
