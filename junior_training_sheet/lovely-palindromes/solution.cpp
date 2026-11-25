#include <bits/stdc++.h>

typedef long long ll;

void init_io();

int main() {
    init_io();

    std::string n;
    std::cin >> n;

    std::string m(n);
    std::reverse(m.begin(), m.end());

    n.append(m);

    std::cout << n << '\n';

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
