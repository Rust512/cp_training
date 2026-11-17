#include <bits/stdc++.h>

void init_io();
char digit_to_char(int);
int char_to_digit(char);
std::string sum_of_digits(const std::string &);

int main() {
    init_io();
    std::string num;
    std::cin >> num;

    int count = 0;
    while (num.length() > 1) {
        num = sum_of_digits(num);
        count++;
    }

    std::cout << count << '\n';
    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

char digit_to_char(int digit) { return (char)('0' + digit); }

int char_to_digit(char ch) { return ch - '0'; }

std::string sum_of_digits(const std::string &num) {
    int sum = 0;
    for (const char ch : num) {
        sum += char_to_digit(ch);
    }

    std::string result;
    while (sum > 0) {
        result.push_back(digit_to_char(sum % 10));
        sum /= 10;
    }

    return result;
}
