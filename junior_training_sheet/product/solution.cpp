#include <bits/stdc++.h>

void init_io();

class big_num {
  private:
    std::string number;
    char digit_to_char(int);
    int char_to_digit(char);

  public:
    big_num(std::string, bool);
    big_num operator+(const big_num &);
    big_num operator-(const big_num &);
    big_num operator*(const big_num &);
    big_num multiply(char, char);
    void trim();
    std::string to_string();
};

int main() {
    init_io();
    std::string num1, num2;

    while (std::cin >> num1 >> num2) {
        big_num op1(num2, false);
        big_num op2(num1, false);
        big_num result = op1 * op2;

        std::cout << result.to_string() << '\n';
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

char big_num::digit_to_char(int digit) {
    assert(digit >= 0 && digit < 10);
    return (char)('0' + digit);
}

int big_num::char_to_digit(char ch) {
    assert(ch >= '0' && ch <= '9');
    return (int)(ch - '0');
}

big_num::big_num(std::string number, bool is_reversed) {
    if (!is_reversed) {
        std::reverse(number.begin(), number.end());
    }

    this->number = number;
}

big_num big_num::operator+(const big_num &other) {
    std::string number = this->number;
    std::string other_number = other.number;

    int target_length = std::max(number.length(), other_number.length());

    number.append(std::string(target_length - number.length(), '0'));
    other_number.append(
        std::string(target_length - other_number.length(), '0'));

    int carry = 0;
    std::string result;

    for (int i = 0; i < target_length; i++) {
        int sum =
            carry + char_to_digit(number[i]) + char_to_digit(other_number[i]);
        result.push_back(digit_to_char(sum % 10));
        carry = sum / 10;
    }

    while (carry > 0) {
        result.push_back(digit_to_char(carry % 10));
        carry /= 10;
    }

    return big_num(result, true);
}

big_num big_num::operator-(const big_num &other) {
    std::string number = this->number;
    std::string other_number = other.number;

    int target_length = std::max(number.length(), other_number.length());

    number.append(std::string(target_length - number.length(), '0'));
    other_number.append(
        std::string(target_length - other_number.length(), '0'));

    // 9's complement.
    for (int i = 0; i < target_length; i++) {
        int digit = char_to_digit(other_number[i]);
        other_number[i] = digit_to_char(9 - digit);
    }

    // 9's complement + 1 = 10's complement.
    int carry = 1;
    std::string result;

    for (int i = 0; i < target_length; i++) {
        int sum =
            carry + char_to_digit(number[i]) + char_to_digit(other_number[i]);
        result.push_back(digit_to_char(sum % 10));
        carry = sum / 10;
    }

    // Omit the last digit to complete subtraction.
    while (carry > 9) {
        result.push_back(digit_to_char(carry % 10));
        carry /= 10;
    }

    return big_num(result, true);
}

big_num big_num::operator*(const big_num &other) {
    std::string number = this->number;
    std::string other_number = other.number;

    int full = std::max(number.length(), other_number.length());

    if (full == 1) {
        return multiply(number[0], other_number[0]);
    }

    if (full % 2 == 1) {
        full++;
    }

    number.append(std::string(full - number.length(), '0'));
    other_number.append(std::string(full - other_number.length(), '0'));

    int half = full / 2;

    big_num a(number.substr(half), true);
    big_num b(number.substr(0, half), true);
    big_num c(other_number.substr(half), true);
    big_num d(other_number.substr(0, half), true);

    big_num op1 = b * d;
    big_num intermediate1 = a * c;
    big_num intermediate2 = (a + b) * (c + d) - op1 - intermediate1;

    big_num op2(std::string(half, '0').append(intermediate2.number), true);
    big_num op3(std::string(full, '0').append(intermediate1.number), true);

    return op1 + op2 + op3;
}

big_num big_num::multiply(char digit1, char digit2) {
    int multiplication = char_to_digit(digit1) * char_to_digit(digit2);
    std::string result;

    while (multiplication > 0) {
        result.push_back(digit_to_char(multiplication % 10));
        multiplication /= 10;
    }

    return big_num(result, true);
}

void big_num::trim() {
    int index = number.length();

    while (number[index - 1] == '0') {
        index--;
    }

    number = (index == 0) ? "0" : number.substr(0, index);
}

std::string big_num::to_string() {
    trim();
    std::string _number = this->number;
    std::reverse(_number.begin(), _number.end());

    return _number;
}
