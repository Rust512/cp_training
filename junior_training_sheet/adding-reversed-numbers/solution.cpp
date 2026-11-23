#include <bits/stdc++.h>

typedef long long ll;

void init_io();
int char_to_digit(char);
char digit_to_char(int);
void solve();

int main() {
    init_io();
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve() {
    std::string op1, op2;
    std::cin >> op1 >> op2;

    int l1 = op1.length();
    int l2 = op2.length();
    int target = std::max(l1, l2);

    op1.append(std::string(target - l1, '0'));
    op2.append(std::string(target - l2, '0'));

    int carry = 0;
    std::string result;
    for (int i = 0; i < target; i++) {
        int sum = carry + char_to_digit(op1[i]) + char_to_digit(op2[i]);
        result.push_back(digit_to_char(sum % 10));
        carry = sum / 10;
    }

    while (carry > 0) {
        result.push_back(digit_to_char(carry % 10));
        carry /= 10;
    }

    int i;
    for (i = 0; i < target; i++) {
        if (result[i] != '0') {
            break;
        }
    }

    std::cout << result.substr(i) << '\n';
}

int char_to_digit(char ch) { return ch - '0'; }
char digit_to_char(int digit) { return (char)('0' + digit); }
