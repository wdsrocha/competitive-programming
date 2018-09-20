#include <bits/stdc++.h>
using namespace std;

struct Number{
    int value;
    string name;
    char chr;
    Number(int value, string name, char chr) :
        value(value), name(name), chr(chr)
    {}
};
vector <Number> numbers;

void removeFreq(map <char, int>& freq, string& number, int val) {
    for (auto chr : number) {
        freq[chr] -= val;
    }
}

string solve(string& phone) {
    map <char, int> freq;
    int sz = phone.size();
    for (int i = 0; i < sz; i++) {
        freq[phone[i]]++;
    }

    vector <int> phone_number;
    for (auto number : numbers) {
        if (freq.find(number.chr) == freq.end()) {
            continue;
        }

        int number_freq = freq[number.chr];
        removeFreq(freq, number.name, number_freq);
        while (number_freq--) {
            phone_number.emplace_back(number.value);
        }
    }

    sort(phone_number.begin(), phone_number.end());
    
    string ans = "";
    for (auto digit : phone_number) {
        ans += (char)(digit+'0');
    }

    return ans;
}

int main() {
    numbers.emplace_back(0, "ZERO",  'Z');
    numbers.emplace_back(2, "TWO",   'W');
    numbers.emplace_back(6, "SIX",   'X');
    numbers.emplace_back(4, "FOUR",  'U');
    numbers.emplace_back(3, "THREE", 'R');
    numbers.emplace_back(5, "FIVE",  'F');
    numbers.emplace_back(1, "ONE",   'O');
    numbers.emplace_back(7, "SEVEN", 'S');
    numbers.emplace_back(8, "EIGHT", 'G');
    numbers.emplace_back(9, "NINE",  'E');

    int case_cnt;
    cin >> case_cnt;
    for (int tc = 1; tc <= case_cnt; tc++) {
        string phone;
        cin >> phone;
        cout << "Case #" << tc << ": " << solve(phone) << endl;
    }

    return 0;
}

