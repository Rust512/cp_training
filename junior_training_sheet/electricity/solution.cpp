#include <bits/stdc++.h>

typedef struct {
    int date;
    int month;
    int year;
    int units;
} consumption_log;

void init_io();
void solve(int);
bool is_one_day_after(consumption_log, consumption_log);
int last_day_of_month(int, int);
bool is_leap_year(int);

int main() {
    init_io();

    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        solve(n);
    }

    return 0;
}

void init_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

void solve(int days) {
    std::vector<consumption_log> logs(days);

    for (auto &x : logs) {
        std::cin >> x.date >> x.month >> x.year >> x.units;
    }

    int count = 0;
    int total = 0;
    for (int i = 1; i < days; i++) {
        if (is_one_day_after(logs[i - 1], logs[i])) {
            count++;
            total += logs[i].units - logs[i - 1].units;
        }
    }

    std::cout << count << ' ' << total << '\n';
}

bool is_one_day_after(consumption_log before, consumption_log after) {
    if (before.year < after.year - 1) {
        return false;
    }

    if (before.year == after.year - 1) {
        return before.month == 12 && before.date == 31 && after.month == 1 &&
               after.date == 1;
    }

    // ATP, before.year == after.year
    if (before.month < after.month - 1) {
        return false;
    }

    if (before.month == after.month - 1) {
        return (before.date == last_day_of_month(before.month, before.year) && after.date == 1);
    }

    // ATP, before.month == after.month as well!
    return before.date == after.date - 1;
}

int last_day_of_month(int month, int year) {
    std::array<int, 13> days_in_month = {0, 31, 28 + (int)is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month];
}

bool is_leap_year(int year) {
    if (year % 100 == 0) {
        return (year % 400 == 0);
    }

    return year % 4 == 0;
}